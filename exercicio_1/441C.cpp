#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, c, k;
  cin >> l >> c >> k;
  vector<pair<int, int>> cls;
  int qnos = l * c / k;

  for (int i = 0; i < l; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < c; j++)
        cls.push_back(make_pair(i, j));
    } else {
      for (int j = c - 1; j >= 0; j--)
        cls.push_back(make_pair(i, j));
    }
  }

  int n = 0;
  for (int w = 0; w < k - 1; w++) {
    cout << qnos;
    for (int ww = 0; ww < qnos; ww++) {
      cout << " " << cls[n].first + 1 << " " << cls[n].second + 1;
      n++;
    }
    cout << endl;
  }
  cout << cls.size() - n;
  while (n < cls.size()) {
    cout << " " << cls[n].first + 1 << " " << cls[n].second + 1;
    n++;
  }
  cout << endl;
}
