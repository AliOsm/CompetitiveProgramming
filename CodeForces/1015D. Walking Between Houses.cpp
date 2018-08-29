/*
  Idea:
    - Greedy.
    - Try to finish `s` with the longest move you have `n - 1`,
      then greedly try to finish the remaining `k` steps.
*/

#include <bits/stdc++.h>

using namespace std;

long long n, k, s;
vector<int> sol;

int main() {
  scanf("%lld %lld %lld", &n, &k, &s);

  if(s < k || s > k * (n - 1)) {
    puts("NO");
    return 0;
  }

  sol.push_back(1);

  bool ok = true;
  long long cur = 1, nxt[] = {1, n};
  while(s >= abs(cur - nxt[ok])) {
    s -= abs(cur - nxt[ok]);
    cur = nxt[ok];
    ok = !ok;
    sol.push_back(cur);
    --k;
  }

  int step;
  if(s == k) {
    if(!ok) {
      step = -1;
      for(int i = cur - 1; k != 0; --k, i += step) {
        if(i == 0)
          i = 2, step = 1;
        if(i == n + 1)
          i = n - 1, step = -1;
        sol.push_back(i);
      }
    } else {
      step = 1;
      for(int i = cur + 1; k != 0; --k, i += step) {
        if(i == 0)
          i = 2, step = 1;
        if(i == n + 1)
          i = n - 1, step = -1;
        sol.push_back(i);
      }
    }
  } else if(s > k) {
    long long need = s - k + 1;
    s -= need;
    --k;
    if(ok) {
      step = 1;
      sol.push_back(sol.back() + need);
      for(int i = sol.back() + 1; k != 0; --k, i += step) {
        if(i == 0)
          i = 2, step = 1;
        if(i == n + 1)
          i = n - 1, step = -1;
        sol.push_back(i);
      }
    } else {
      step = -1;
      sol.push_back(sol.back() - need);
      for(int i = sol.back() - 1; k != 0; --k, i += step) {
        if(i == 0)
          i = 2, step = 1;
        if(i == n + 1)
          i = n - 1, step = -1;
        sol.push_back(i);
      }
    }
  } else {
    while(s < k) {
      sol.pop_back();
      s += abs(1 - n);
      ++k;
      ok = !ok;
    }
    long long need = s - k + 1;
    s -= need;
    --k;
    if(ok) {
      step = 1;
      sol.push_back(sol.back() + need);
      for(int i = sol.back() + 1; k != 0; --k, i += step) {
        if(i == 0)
          i = 2, step = 1;
        if(i == n + 1)
          i = n - 1, step = -1;
        sol.push_back(i);
      }
    } else {
      step = -1;
      sol.push_back(sol.back() - need);
      for(int i = sol.back() - 1; k != 0; --k, i += step) {
        if(i == 0)
          i = 2, step = 1;
        if(i == n + 1)
          i = n - 1, step = -1;
        sol.push_back(i);
      }
    }
  }

  puts("YES");
  for(int i = 1; i < sol.size(); ++i)
    printf("%d ", sol[i]);
  puts("");

  return 0;
}
