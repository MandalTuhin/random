#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void removeDuplicates(vector<int> &nums) {
    int slow = 0, fast = 1;
    while (fast < nums.size()) {
      if (nums[slow] == nums[fast]) {
        fast++;
      } else {
        nums[++slow] = nums[fast];
      }
    }
  }
};

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution solution;
  solution.removeDuplicates(nums);
  for (int elem : nums) {
    cout << elem << " ";
  }
  return 0;
}
