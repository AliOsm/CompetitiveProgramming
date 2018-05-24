/*
	Idea:
		- Greedy.
		- Imagine each query as a n-ary tree, you will see that you will add each number
			x times, where x is the level of the number in the tree.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int n, q;
long long a[N], mem[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
  	scanf("%lld", a + i);
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; ++i)
  	a[i] += a[i-1];

  memset(mem, -1, sizeof mem);
  scanf("%d", &q);
  while(q-- != 0) {
  	long long k, cur;
  	scanf("%lld", &k);
  	cur = k;

  	if(k >= n - 1) {
  		printf("%lld ", a[n-1]);
  		continue;
  	}

  	if(mem[k] != -1) {
  		printf("%lld ", mem[k]);
  		continue;
  	}

  	long long res = 0;
  	for(int i = n - 1; i > 0; i -= cur, cur = min(cur * k, 1ll * n))
  		res += a[i];

  	printf("%lld ", res);
  	mem[k] = res;
  }

  puts("");

  return 0;
}
