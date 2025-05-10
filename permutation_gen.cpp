#include <algorithm>
using namespace std;
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  void backtrack(string &s, int index, unordered_set<string> &result) {
    if (index == s.size()) {
      result.insert(s);
      return;
    }

    for (int i = index; i < s.size(); ++i) {
      swap(s[i], s[index]);
      backtrack(s, index + 1, result);
      swap(s[i], s[index]); // backtrack
    }
  }

  vector<string> getPermutations(string num) {
    unordered_set<string> result; // to avoid duplicates
    backtrack(num, 0, result);
    return vector<string>(result.begin(), result.end());
  }
};
