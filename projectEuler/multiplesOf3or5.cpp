#include <iostream>
using namespace std;

long long multiplesOf3or5(int upperRange) {
  long long sum = 0;
  for (int i = 1; i < upperRange; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  int upperRange = 1000;
  cout << multiplesOf3or5(upperRange);
}
