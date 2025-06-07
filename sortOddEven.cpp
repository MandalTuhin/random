#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortEvenOdd(vector<int> &nums) {
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < nums.size(); i++) {
      i % 2 != 0 ? odd.push_back(nums[i]) : even.push_back(nums[i]);
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end());
    int counter = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      nums[i] = even[counter++];
    }
    counter = 0;
    for (int i = 1; i < nums.size(); i += 2) {
      nums[i] = odd[counter++];
    }
    return nums;
  }
};

int main() {
  vector<int> nums = {4, 1, 2, 3};
  Solution solution;
  vector<int> result = solution.sortEvenOdd(nums);
  for (int elem : result) {
    cout << elem;
  }
  return 0;
}
