#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef bool binary;

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  binary stateOfButton = false;
  for (int elem : a) {
    if (!elem) {
      if (stateOfButton == true)
        t--;
      continue;
    } else {
      if (stateOfButton == false)
        stateOfButton = true;
      else
        t--;
    }
  }

  t >= 0 ? cout << "YES \n" : cout << "NO \n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T; // Input the number of test cases
  while (T--)
    solve();
  return 0;
}
