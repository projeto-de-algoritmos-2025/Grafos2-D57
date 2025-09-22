#include <bits/stdc++.h>
using namespace std;

/*
 * Qual o intuito da minha dfs?
 *  Vou rodar xs dfs, onde, percorro o vetor até tal posicao,indo de lado,achei
 * xs quadrados, quebra de linha
 */

void dfs(vector<vector<bool>> mtx, int l, int c, int i, int j, int tmp,
         int tmp2, int qnos, int tubos) {
  if (tmp == qnos) {
    ++tmp2;
    cout << endl;
    if (tmp2 < tubos)
      cout << qnos;
    tmp = 0;
  }
  if (i == l) {
    i = 0;
    j++;
  }
  if (j == c)
    return;
  if (i <= l) {
    cout << " " << i + 1 << " " << j + 1;
    tmp++;
    dfs(mtx, l, c, ++i, j, tmp++, tmp2, qnos, tubos);
  }
}

int main() {
  int l, c, k;
  cin >> l >> c >> k;
  vector<vector<bool>> mtx;
  int qnos = l * c / k;
  for (int i = 0; i < l; i++) {
    vector<bool> tmp;
    for (int j = 0; j < c; j++) {
      tmp.push_back(false);
    }
    mtx.push_back(tmp);
  }

  // for (auto x : mtx) {
  //   for (auto y : x) {
  //     cout << y << " ";
  //   }
  //   cout << endl;
  // }

  cout << qnos;
  dfs(mtx, l, c, 0, 0, 0, 0, qnos, k);
}
