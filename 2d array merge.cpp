#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    vector<vector<int>> result;
    int first = 0, second = 0;
    while (first < nums1.size() && second < nums2.size()) {
      if (nums1[first][0] == nums2[second][0]) {
        result.push_back({nums1[first][0], nums1[first][1] + nums2[second][1]});
        first++;
        second++;
      } else if (nums1[first][0] > nums2[second][0]) {
        result.push_back(nums2[second]);
        second++;
      } else {
        result.push_back(nums1[first]);
        first++;
      }
      cout << "the for loop is stuck here \n";
    }

    if (first == nums1.size()) {
      while (second < nums2.size()) {
        result.push_back(nums2[second++]);
      }
    } else {
      while (first < nums1.size()) {
        result.push_back(nums1[first++]);
      }
    }
    return result;
  }
};

int main() {
  vector<vector<int>> nums1 = {{2, 4}, {3, 6}, {5, 5}};
  vector<vector<int>> nums2 = {{1, 3}, {4, 3}};
  Solution solution;
  vector<vector<int>> result = solution.mergeArrays(nums1, nums2);
  for (vector<int> elem : result) {
    for (int each_elem : elem) {
      cout << each_elem << ", ";
    }
    cout << "\n";
  }

  return 0;
}
