/*
  Idea:
    - Comulative sum.
    - For each person put -1 in its index and put 1 in `i - a[i]` then do comulative sum.
    - Number of zeros is the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int n, a[N], cs[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
  	scanf("%d", a + i);
  	--cs[i];
  	++cs[max(0, i - a[i])];
  }

  for(int i = 1; i < n; ++i)
  	cs[i] += cs[i-1];

  int cnt = 0;
  for(int i = 0; i < n; ++i)
  	if(cs[i] == 0)
  		++cnt;

  printf("%d\n", cnt);

  return 0;
}
