/*
  Idea:
    - Calculate the minimum number of rows needed.
    - Calculate the minimum number of cols needed.
    - Calculate the spaces where we need to put asterisks
      on them.
    - Divide the asterisks equally on the rows and the remaining
      asterisks distribute them on the rows one by one.
*/

#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  int len = s.length();

  int row = ceil(len / 20.0);
  int col;
  for(int i = 1; i <= 20; ++i)
    if(row * i >= len) {
      col = i;
      break;
    }

  int ast = row * col - len;
  int ech = ast / row;
  int rem = ast % row;

  vector<int> asts;
  for(int i = 0, cur; i < row; ++i) {
    cur = ech;
    if(rem > 0)
      ++cur, --rem;
    asts.push_back(cur);
  }

  printf("%d %d\n", row, col);
  int cnt = 0;
  for(int i = 0; cnt < len && i < row; ++i, puts("")) {
    for(int j = 0; cnt < len && j < col - asts[i]; ++j) {
      printf("%c", s[cnt]);
      ++cnt;
    }
    for(int j = 0; j < asts[i]; ++j)
      printf("*");
  }

  return 0;
}
