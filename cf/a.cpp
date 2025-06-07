#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  int mi = *min_element(all(a));
  int mx = *max_element(all(a));

  if ((mi + mx) % 2 == 0) {
    cout << 0 << endl;
  } else {

    cout << 1 << endl;
  }
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
