#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &x : a)
    cin >> x;

  // int mi = *min_element(all(a));
  // int mx = *max_element(all(a));
  //
  // if ((mi + mx) % 2 == 0) {
  //   cout << 0 << endl;
  // } else {
  //   cout << 1 << endl;
  // }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < a[i].size(); j++) {
      if (a[i][j] == '#') {
        cout << j + 1 << " ";
      }
    }
  }
  cout << endl;
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
