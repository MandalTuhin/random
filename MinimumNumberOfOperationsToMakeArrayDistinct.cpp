#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  bool checkDistinct(vector<int> &nums) {
    unordered_set<int> occurances;
    for (int i = 0; i < nums.size(); i++) {
      if (!occurances.count(nums[i])) {
        occurances.insert(nums[i]);
      } else {
        return false;
      }
    }
    return true;
  }

public:
  int minimumOperations(vector<int> &nums) {
    int noOfOperations = 0;
    while (!checkDistinct(nums) && nums.size() > 0) {
      if (nums.size() >= 3) {
        nums.erase(nums.begin(), nums.begin() + 3);
      } else {
        nums.erase(nums.begin(), nums.end());
      }
      noOfOperations++;
      cout << "this is the loop that is looping infinitely. \n";
    }
    return noOfOperations;
  }
};

int main() {
  vector<int> nums = {4, 5, 6, 4, 4};
  Solution solution;
  int result = solution.minimumOperations(nums);
  cout << result;
  return 0;
}
