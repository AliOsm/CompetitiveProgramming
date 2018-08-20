/*
  Idea:
    - Recursion with pruning.
    - We can try to put 0 or 1 in each place in the binary representation
      of the number, but we need to check that if we put 1 and we can not
      reach the number `n` in the future we can skip this branch.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 65;
char s[N];
int t, k, sol[N];
long long n;
long long pos[N], neg[N], cpos[N], cneg[N];

bool rec(int idx, long long num) {
  if(idx == k) {
    if(n == num) {
      for(int i = 0; i < k; ++i)
        printf("%d", sol[i]);
      puts("");
      return true;
    }

    return false;
  }

  sol[idx] = 1;
  if(s[idx] == 'p') {
    if(num + pos[idx] - (cneg[k] - cneg[idx]) > n) {
      sol[idx] = 0;
      if(rec(idx + 1, num))
        return true;
    } else {
      if(rec(idx + 1, num + pos[idx]))
        return true;
    }
  } else {
    if(num - neg[idx] + (cpos[k] - cpos[idx]) < n) {
      sol[idx] = 0;
      if(rec(idx + 1, num))
        return true;
    } else {
      if(rec(idx + 1, num - neg[idx]))
        return true;
    }
  }

  return false;
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    for(int i = 0; i < k; ++i)
      pos[i] = neg[i] = 0;

    scanf("%d", &k);
    scanf("%s", s);
    scanf("%lld", &n);

    for(int i = 0; i < k; ++i)
      if(s[i] == 'p')
        pos[i] = (1llu << ((k - 1) - i));
      else
        neg[i] = (1llu << ((k - 1) - i));

    for(int i = 1; i <= k; ++i) {
      cpos[i] = pos[i - 1] + cpos[i - 1];
      cneg[i] = neg[i - 1] + cneg[i - 1];
    }

    if(!rec(0, 0))
      puts("Impossible");
  }
  
  return 0;
}
