#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  // helper funtion to find the maximum frequent elem in the unordered_map;
private:
  pair<int, int> max_elem_along_frequency(unordered_map<int, int> &frequency) {
    int max = 0;
    int max_index = 0;
    for (const auto pair : frequency) {
      if (pair.second > max) {
        max = pair.second;
        max_index = pair.first;
      }
    }
    frequency.erase(max);
    return {max, max_index};
  }

public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // first solution; I will try to count the frequency of each element and
    // then sort the array;
    //  and then return the first k elements;
    unordered_map<int, int> frequency;
    for (int elem : nums) {
      frequency[elem]++;
    }
    int i = 0, j = 0;
    while (i < nums.size()) {
      pair<int, int> max = max_elem_along_frequency(frequency);
      j = i;
      while (i < j + max.second) {
        nums[i++] = max.first;
      }
    }
    i = 1;
    vector<int> result;
    result.push_back(nums[0]);
    k--;
    for (int i = 0; i < nums.size() - 1 && k > 0; i++) {
      if (nums[i] != nums[i + 1]) {
        result.push_back(nums[i + 1]);
        k--;
      }
    }
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 2, 3, 3, 3};
  int k = 2;
  Solution solution;
  vector<int> result = solution.topKFrequent(nums, k);
  for (int elem : result) {
    cout << elem;
  }
  return 0;
}
