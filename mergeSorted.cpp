#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> res;
    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < m && ptr2 < n) {
      // I will have to select the smaller of two values at ptr1 and ptr2;
      if (nums1[ptr1] < nums2[ptr2]) {
        res.push_back(nums1[ptr1++]);

      } else {
        res.push_back(nums2[ptr2++]);
      }
    }

    if (ptr1 == m) {
      while (ptr2 < n)
        res.push_back(nums2[ptr2++]);
    } else {
      while (ptr1 < m)
        res.push_back(nums1[ptr1++]);
    }

    for (int i = 0; i < nums1.size(); i++) {
      nums1[i] = res[i];
    }
  }
};

int main() {
  vector<int> nums1 = {1, 1, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  Solution solution;
  solution.merge(nums1, 3, nums2, 3);
  for (int elem : nums1) {
    cout << elem << " ";
  }
  return 0;
}
