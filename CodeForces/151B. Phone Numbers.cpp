#include <bits/stdc++.h>

using namespace std;

int n, s, con[101][3], idx[6] = {0, 1, 3, 4, 6, 7};
char name[101][21], cur[10];
vector<string> sol[3];

int what() {
  bool ok;

  ok = true;
  for(int i = 1; i < 6; ++i)
    if(cur[idx[i]] != cur[idx[i - 1]]) {
      ok = false;
      break;
    }

  if(ok)
    return 0;

  ok = true;
  for(int i = 1; i < 6; ++i)
    if(cur[idx[i]] - '0' >= cur[idx[i - 1]] - '0') {
      ok = false;
      break;
    }

  if(ok)
    return 1;

  return 2;
}

int main() {
  int mx[3] = {0};

  scanf("%d", &n);
  for(int j = 0; j < n; ++j) {
    scanf("%d %s", &s, name[j]);

    for(int i = 0; i < s; ++i) {
      scanf("%s", cur);
      ++con[j][what()];
    }

    for(int i = 0; i < 3; ++i)
      mx[i] = max(mx[i], con[j][i]);
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < 3; ++j)
      if(con[i][j] == mx[j])
        sol[j].push_back(name[i]);

  printf("If you want to call a taxi, you should call: ");
  for(int i = 0; i < sol[0].size(); ++i) {
    if(i != 0)
      printf(", ");
    printf("%s", sol[0][i].c_str());
  }
  puts(".");

  printf("If you want to order a pizza, you should call: ");
  for(int i = 0; i < sol[1].size(); ++i) {
    if(i != 0)
      printf(", ");
    printf("%s", sol[1][i].c_str());
  }
  puts(".");

  printf("If you want to go to a cafe with a wonderful girl, you should call: ");
  for(int i = 0; i < sol[2].size(); ++i) {
    if(i != 0)
      printf(", ");
    printf("%s", sol[2][i].c_str());
  }
  puts(".");

  return 0;
}
