#include <bits/stdc++.h>

using namespace std;

int const N = (1 << 18);
int n, q, a[N], seg[4 * N];

void build(int idx, int L, int R, int lvl) {
  if(L == R) {
    seg[idx] = a[L];
    return;
  }
  
  int mid = (L + R) >> 1;
  build(idx * 2, L, mid, lvl - 1);
  build((idx * 2) + 1, mid + 1, R, lvl - 1);
  
  if(lvl % 2 == 0)
    seg[idx] = seg[idx * 2] ^ seg[(idx * 2) + 1];
  else
    seg[idx] = seg[idx * 2] | seg[(idx * 2) + 1];
}

int tar, val;
void update(int idx, int L, int R, int lvl) {
  if(tar < L || tar > R)
    return;
  
  if(L == R) {
    seg[idx] = val;
    return;
  }
  
  int mid = (L + R) >> 1;
  update(idx * 2, L, mid, lvl - 1);
  update((idx * 2) + 1, mid + 1, R, lvl - 1);
  
  if(lvl % 2 == 0)
    seg[idx] = seg[idx * 2] ^ seg[(idx * 2) + 1];
  else
    seg[idx] = seg[idx * 2] | seg[(idx * 2) + 1];
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= (1 << n); ++i)
    scanf("%d", a + i);
  
  build(1, 1, (1 << n), n);
  
  for(int i = 0; i < q; ++i) {
    scanf("%d %d", &tar, &val);
    update(1, 1, (1 << n), n);
    printf("%d\n", seg[1]);
  }
  
  return 0;
}

