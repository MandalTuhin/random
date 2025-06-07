#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
  long long fibboSumTillUpperRange(long long upperRange) {
    // This problem will require the use of dynamic programming. I will go with
    // the iterative approach because I don't know how to implement memoization.
    long long sum = 0;
    vector<long long> fibbNum;
    fibbNum.push_back(1);
    fibbNum.push_back(1);
    int i = 2; // for indexing
    while (fibbNum[i - 1] + fibbNum[i - 2] <= upperRange) {
      fibbNum.push_back(fibbNum[i - 1] + fibbNum[i - 2]);
      i++;
    }

    for (int i = 1; i < fibbNum.size(); i++) {
      if (fibbNum[i] % 2 == 0)
        sum += fibbNum[i];
    }

    return sum;
  }
};

int main() {
  long long upperRange = 4000000;
  Solution solution;
  cout << solution.fibboSumTillUpperRange(upperRange);
  return 0;
}
