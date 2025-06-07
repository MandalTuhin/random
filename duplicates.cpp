#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    // I will try to use a hash map as my first approach. I will try to
    // optimize with a
    //  an array of size(n); and will store the frequency there;
    // sorting can be another approach here, but it would lead to O(n logn)
    // time, which is not allowed here.
    // I will use the indices to track whether an element has occured twices or
    // not.

    for (int i = 0; i < nums.size(); i++) {
      // 0 -> 1, 0 will be treated as 1. k will be treated as k + 1; or vice
      // versa;
      nums[(nums[i] - 1) % 1000] = 1000 + nums[(nums[i] - 1) % 1000];
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 2000)
        res.push_back(nums[i] % 1000);
    }
    return res;
  }
};

int main() {
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution solution;
  vector<int> res = solution.findDuplicates(nums);
  for (int elem : res) {
    cout << elem << " ";
  }
  return 0;
}
