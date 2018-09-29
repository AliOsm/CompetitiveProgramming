/*
  Idea:
    - https://www.geeksforgeeks.org/print-longest-common-sub-sequences-lexicographical-order/
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int t, len, l1, l2, dp[N][N];
char s1[N], s2[N];
string s;
vector<string> sol;

int rec(int i, int j) {
  if(i == l1 || j == l2)
    return 0;

  int &ret = dp[i][j];
  if(ret != -1)
    return ret;
  ret = 0;

  if(s1[i] == s2[j])
    return ret = rec(i + 1, j + 1) + 1;
  ret = max(ret, rec(i + 1, j));
  ret = max(ret, rec(i, j + 1));

  return ret;
}

void print(int i, int j, int l) {
  if(l == len) {
    sol.push_back(s);
    return;
  }

  if(i == l1 || j == l2)
    return;

  for(char c = 'a'; c <= 'z'; ++c) {
    bool ok = false;
    for(int ii = i; ii < l1; ++ii) {
      if(s1[ii] == c) {
        for(int jj = j; jj < l2; ++jj) {
          if(s2[jj] == c && rec(ii, jj) == len - l) {
            s += c;
            print(ii + 1, jj + 1, l + 1);
            s.pop_back();
            ok = true;
            break;
          }
        }
      }
      if(ok)
        break;
    }
  }
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%s\n%s", s1, s2);
    l1 = strlen(s1);
    l2 = strlen(s2);

    memset(dp, -1, sizeof dp);
    len = rec(0, 0);

    s = "";
    sol.clear();
    print(0, 0, 0);

    for(int i = 0; i < sol.size(); ++i)
      printf("%s\n", sol[i].c_str());

    if(t)
      puts("");
  }

  return 0;
}
