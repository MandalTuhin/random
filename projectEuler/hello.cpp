#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
public:
  int sumOfOddIndices(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 != 0)
        res += nums[i];
    }

    return res;
  }
};

int main() {
  int n = 0;
  cin >> n;
  vector<int> nums(n);
  for (auto &a : nums) {
    cin >> a;
  }

  Solution solution;
  cout << solution.sumOfOddIndices(nums);
  return 0;
}
