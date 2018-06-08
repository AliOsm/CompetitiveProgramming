#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, k, a[N], nxt[N], res;

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i)
  	scanf("%d", a + i);
  sort(a, a + n);

  memset(nxt, -1, sizeof nxt);
  for(int i = 0, idx; i < n - 1; ++i) {
  	idx = lower_bound(a, a + n, 1ll * a[i] * k) - a;
  	if(idx == i || idx == n || 1ll * a[i] * k != a[idx])
  		continue;
  	nxt[i] = idx;
  }

  for(int i = 0, cur, prv, cnt; i < n; ++i) {
  	if(nxt[i] == 1e9)
  		continue;
  	if(nxt[i] == -1) {
  		++res;
  		continue;
  	}
  	cur = prv = i, cnt = 0;
  	while(nxt[cur] != -1) {
  		if(cnt % 2 == 0)
  			++res;
  		prv = cur, cur = nxt[cur], nxt[prv] = 1e9, ++cnt;
  	}
  	if(cnt + 1 & 1)
  		++res;
  	nxt[cur] = 1e9;
  }

  printf("%d\n", res);

  return 0;
}
