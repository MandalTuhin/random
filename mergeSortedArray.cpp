#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> combined(m + n, 0);
    int mth = 0, nth = 0;
    int i = 0;
    while (mth < m && nth < n) {
      if (nums1[mth] >= nums2[nth]) {
        combined[i] = nums2[nth];
        cout << "nums2s " << nums2[nth] << " wins here; \n";
        nth++;
      } else {
        combined[i] = nums1[mth];
        cout << "num1s " << nums1[mth] << " wins here; \n";
        mth++;
      }
      i++;
    }

    // checking which pointer ran out first, and will push the remaining
    // elements of the other array into combined.
    if (mth == m) {
      while (nth < n) {
        combined[i] = nums2[nth];
        i++;
        nth++;
      }
    } else {
      while (mth < n) {
        combined[i] = nums1[mth];
        i++;
        mth++;
      }
    }

    // printing the combined vector for debugging.
    for (int elem : combined) {
      cout << elem << " ";
    }

    cout << " \n";

    for (int i = 0; i < nums1.size(); i++) {
      nums1[i] = combined[i];
    }
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  Solution solution;
  solution.merge(nums1, 3, nums2, 3);
  for (int elem : nums1) {
    cout << elem << " ";
  }
  return 0;
}
