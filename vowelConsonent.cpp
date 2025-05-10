#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int maxFreqSum(string s) {
    vector<int> frequency(26, 0);
    for (size_t i = 0; i < s.size(); i++) {
      frequency[tolower(s[i]) - 'a']++;
    }

    for (int elem : frequency) {
      cout << elem << " ";
    }

    cout << "\n";

    vector<int> vowels = {0, 4, 8, 14, 20};
    int vowel_max = INT_MIN, cons_max = INT_MIN;
    // for loop for vowels
    for (int i = 0; i < vowels.size(); i++) {
      if (frequency[vowels[i]] > vowel_max) {
        vowel_max = frequency[vowels[i]];
      }
      frequency[vowels[i]] = 0;
    }

    // printing the vector for debugging.
    for (int elem : frequency) {
      cout << elem << " ";
    }

    cout << "\n";

    for (int i = 0; i < frequency.size(); i++) {
      if (frequency[i] > cons_max)
        cons_max = frequency[i];
    }

    for (int elem : frequency) {
      cout << elem << " ";
    }

    return vowel_max + cons_max;
  }
};

int main() {
  string s = "aeiaeia";
  Solution solution;
  int result = solution.maxFreqSum(s);
  // cout<< result;
  return 0;
}
