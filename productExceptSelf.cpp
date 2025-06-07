#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size(), 0);
    vector<int> prefixArray(nums.size() + 2, 1);
    vector<int> suffixArray(nums.size() + 2, 1);
    // I will fill up the first and last of both the prefix and suffix array
    // with 1;
    prefixArray[0] = prefixArray[prefixArray.size() - 1] = 1;
    suffixArray[0] = suffixArray[suffixArray.size() - 1] = 1;

    // enumerating the prefixArray and suffixArray
    int i = 0, j = nums.size() - 1;
    while (i < nums.size() && j >= 0) {
      prefixArray[i + 1] = prefixArray[i] * nums[i];
      suffixArray[j + 1] = suffixArray[j + 2] * nums[j];
      i++;
      j--;
    }
    // for (int i = 0; i < nums.size(); i++) {
    //   prefixArray[i + 1] = prefixArray[i] * nums[i];
    // }

    for (int elem : prefixArray) {
      cout << elem << " ";
    }
    cout << "\n";

    for (int elem : suffixArray) {
      cout << elem << " ";
    }
    cout << "\n";

    // both arrays can now be used to solve the problem;

    for (int i = 0; i < nums.size(); i++) {
      nums[i] = prefixArray[i] * suffixArray[i + 2];
    }

    return nums;
  }
};

int main() {
  vector<int> nums = {1, 2, 4, 6};
  Solution solution;
  vector<int> res = solution.productExceptSelf(nums);
  for (int elem : res) {
    cout << elem << " ";
  }
  return 0;
}
