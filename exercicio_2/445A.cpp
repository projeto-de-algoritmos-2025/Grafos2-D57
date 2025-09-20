#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;

  vector<string> B(n);
  for (string &s : B)
    cin >> s;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (B[i][j] == '-') cout << '-';
      else {
        if ((i + j) % 2 == 0) cout << 'B';
        else cout << 'W';
      }
    }
    cout << '\n';
  }

  return 0;
}
