#include <bits/stdc++.h>

using namespace std;

struct query {
  int t, l, r;
};

int const N = 2e5 + 1;
int n, q, m, a[N];
query all[N];

int main() {
  scanf("%d %d %d", &n, &q, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < q; ++i)
    scanf("%d %d %d", &all[i].t, &all[i].l, &all[i].r);
  
  for(int i = 0, cur; i < m; ++i) {
    scanf("%d", &cur);
    
    for(int j = q - 1; j >= 0; --j) {
      if(cur >= all[j].l && cur <= all[j].r) {
        if(all[j].t == 1) {
          --cur;
          if(cur < all[j].l)
            cur = all[j].r;
        } else {
          int len = all[j].r - all[j].l + 1;
  				cur -= all[j].l;
  				cur = len - cur - 1;
  				cur += all[j].l;
        }
      }
    }
    
    printf("%d ", a[--cur]);
  }
  
  return 0;
}
