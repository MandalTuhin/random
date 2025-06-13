#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // size of input;
  cin >> n;
  vector<int> nums(n - 1, 0);
  for (int &x : nums) {
    cin >> x;
  }
  int missingNum = 0, i = 0;
  for (i = 0; i < nums.size(); i++) {
    missingNum ^= i ^ nums[i];
  }
  missingNum ^= i;
  missingNum ^= n;

  cout << missingNum;
}
