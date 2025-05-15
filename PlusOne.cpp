#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int number = 0;
    // vector<int> result;
    for (int i = 0; i < digits.size(); i++) {
      number = number * 10 + digits[i];
    }
    number++;
    int temp = number, i = 0;
    while (temp > 0) {
      i++;
      temp /= 10;
    }
    vector<int> result(i, 0);
    while (number > 0) {
      result[(i--) - 1] = number % 10;
      cout << i << "\n";
      number /= 10;
    }
    return result;
  }
};

int main() {
  vector<int> digits = {1, 2, 3};
  Solution solution;
  vector<int> result = solution.plusOne(digits);
  for (int elem : result) {
    cout << elem << " ";
  }
  return 0;
}
