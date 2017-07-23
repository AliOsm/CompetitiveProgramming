#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int const N = 1e5 + 1;
long long n, a[N], seg[4 * N];

void build(int idx, int L, int R) {
  if(L == R) {
    seg[idx] = a[L];
    return;
  }
  
  int mid = (L + R) >> 1;
  build(idx << 1, L, mid);
  build((idx << 1) + 1, mid + 1, R);
  seg[idx] = seg[idx << 1] + seg[(idx << 1) + 1];
}

int S, E;

void update(int idx, int L, int R) {
  if(E < L || S > R)
    return;
  
  if(L == R) {
    seg[idx] = a[L] = sqrt(a[L]);
    return;
  }
  
  if(seg[idx] == R - L + 1)
    return;
  
  int mid = (L + R) >> 1;
  update(idx << 1, L, mid);
  update((idx << 1) + 1, mid + 1, R);
  seg[idx] = seg[idx << 1] + seg[(idx << 1) + 1];
}

long long get(int idx, int L, int R) {
  if(E < L || S > R)
    return 0;
  
  if(L >= S && R <= E)
    return seg[idx];
  
  int mid = (L + R) >> 1;
  return get(idx << 1, L, mid) + get((idx << 1) + 1, mid + 1, R);
}

int main() {
  for(int kase = 1; scanf("%d", &n) != EOF; ++kase) {
    printf("Case #%d:\n", kase);
    
    for(int i = 1; i <= n; ++i)
      scanf("%lld", a + i);
    build(1, 1, n);
    
    int q;
    scanf("%d", &q);
    
    int type;
    
    while(q-- != 0) {
      scanf("%d %d %d", &type, &S, &E);
      
      if(S > E)
        swap(S, E);
      
      if(type == 0)
        update(1, 1, n);
      else
        printf("%lld\n", get(1, 1, n));
    }
    
    puts("");
  }
  
  return 0;
}
