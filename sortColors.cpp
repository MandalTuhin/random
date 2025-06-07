#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int zeros = 0, ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        zeros++;
      else if (nums[i] == 1)
        ones++;
      else if (nums[i] == 2)
        twos++;
    }

    cout << zeros << " " << ones << " " << twos << "\n";

    for (int i = 0; i < nums.size(); i++) {
      if (i < zeros)
        nums[i] = 0;
      else if (i >= zeros && i < ones + zeros)
        nums[i] = 1;
      else if (i >= ones + zeros && i < twos + ones + zeros)
        nums[i] = 2;
    }
  }
};

int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution solution;
  solution.sortColors(nums);
  for (int elem : nums) {
    cout << elem << " ";
  }
  return 0;
}
