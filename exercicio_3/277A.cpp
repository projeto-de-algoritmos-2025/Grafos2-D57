#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> pa;
  DSU(int n) {
    pa.resize(n + 1);
    iota(pa.begin(), pa.end(), 0);
  }

  int find(int i) {
    if (pa[i] == i)
      return i;
    return pa[i] = find(pa[i]);
  }

  void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j)
      pa[root_i] = root_j;
  }
};

void print_graph(vector<vector<int>> L, int m) {
  for (int lang = 1; lang <= m; ++lang) {
    cout << lang << ": ";
    int size = L[lang].size();
    if (size == 0) {
      cout << '\n';
      continue;
    }
    for (int i = 0; i < size; ++i) {
      cout << L[lang][i] << ((i + 1 == size) ? '\n' : ' ');
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<vector<int>> L(m + 1);

  bool missing = false;
  
  for (int i = 1; i <= n; ++i) {
    int langs; cin >> langs;
    if (langs > 0)
      missing = true;
    for (int j = 0; j < langs; ++j) {
      int lang; cin >> lang;
      L[lang].emplace_back(i);
    }
  }

  if (!missing) {
    cout << n << '\n';
    return 0;
  }

  DSU dsu(n + 1);

  for (int lang = 1; lang <= m; ++lang) {
    int size = L[lang].size();
    if (size > 1) {
      int pivo = L[lang][0];
      for (int i = 1; i < size; ++i)
        dsu.unite(pivo, L[lang][i]);
    }
  }

  int componenets = 0;
  vector<bool> visited(n + 1, false);
  for (int i = 1; i <=n; ++i) {
    int root = dsu.find(i);
    if (!visited[root]) {
      componenets++;
      visited[root] = true;
    }
  }

  cout << componenets - 1 << '\n';

  return 0;
}
