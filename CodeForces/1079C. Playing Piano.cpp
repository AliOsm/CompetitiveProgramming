/*
  Idea:
    - Dynamic Programming
    - If you reach the base case in the recursion, then
      you have an answer, so print it.
    - This method work if the dynamic programming answer
      is true or false.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], dp[N][6];
vector<int> sol;

int rec(int idx, int prv) {
  if(idx == n) {
    for(int i = 0; i < sol.size(); ++i)
      printf("%s%d", i == 0 ? "" : " ", sol[i]);
    puts("");
    exit(0);
  }

  int &ret = dp[idx][prv];
  if(ret != -1)
    return ret;
  ret = 0;

  if(a[idx] == a[idx - 1]) {
    for(int i = 1; i <= 5; ++i)
      if(i != prv) {
        sol.push_back(i);
        rec(idx + 1, i);
        sol.pop_back();
      }
  }

  if(a[idx] > a[idx - 1]) {
    for(int i = prv + 1; i <= 5; ++i) {
      sol.push_back(i);
      rec(idx + 1, i);
      sol.pop_back();
    }
  }

  if(a[idx] < a[idx - 1]) {
    for(int i = prv - 1; i >= 1; --i) {
      sol.push_back(i);
      rec(idx + 1, i);
      sol.pop_back();
    }
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  memset(dp, -1, sizeof dp);
  for(int i = 1; i <= 5; ++i) {
    sol.push_back(i);
    if(rec(1, i))
      return 0;
    sol.pop_back();
  }
  puts("-1");

  return 0;
}
