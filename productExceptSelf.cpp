#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    // first solution:
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int product = 1;
      for (int j = 0; j < nums.size(); j++) {
        if (j != i)
          product *= nums[j];
      }
      cout << product << " ";
      cout << "\n";
      res.push_back(product);
    }

    return res;
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
