#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, k, a[N], seg[4 * N], prv[N], nxt[N], res[N];
vector<int> t1, t2;
set<int> st_inc, st_dec;

void build(int at, int l, int r) {
  if(l == r) {
    seg[at] = l;
    return;
  }

  int mid = (l + r) >> 1;
  build(at << 1, l, mid);
  build(at << 1 | 1, mid + 1, r);

  if(a[seg[at << 1]] > a[seg[at << 1 | 1]])
    seg[at] = seg[at << 1];
  else
    seg[at] = seg[at << 1 | 1];
}

int s, e;
int get(int at, int l, int r) {
  if(l > e || r < s)
    return 0;
  
  if(l >= s && r <= e)
    return seg[at];
  
  int mid = (l + r) >> 1;

  int gl = get(at << 1, l, mid);
  int gr = get(at << 1 | 1, mid + 1, r);

  if(a[gl] > a[gr])
    return gl;
  return gr;
}

int tar;
void update(int at, int l, int r) {
  if(l > tar || r < tar)
    return;

  if(l == r) {
    a[l] = -1;
    return;
  }

  int mid = (l + r) >> 1;
  update(at << 1, l, mid);
  update(at << 1 | 1, mid + 1, r);

  if(a[seg[at << 1]] > a[seg[at << 1 | 1]])
    seg[at] = seg[at << 1];
  else
    seg[at] = seg[at << 1 | 1];
}

int main() {
  a[0] = -1;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    st_inc.insert(i);
    st_dec.insert(-i);
    nxt[i] = i + 1;
    prv[i] = i - 1;
  }
  
  build(1, 1, n);

  s = 1, e = n;
  for(int i = 0, mxi, flst, blst; t1.size() + t2.size() < n; ++i) {
    flst = blst = -1;
    mxi = get(1, 1, n);

    for(int j = mxi, cnt = 0; cnt <= k && j <= n; ++cnt, j = nxt[j]) {
      tar = flst = j;
      update(1, 1, n);
      if(i % 2 == 0)
        t1.push_back(j);
      else
        t2.push_back(j);
      st_inc.erase(tar);
      st_dec.erase(-tar);
    }

    for(int j = prv[mxi], cnt = 1; cnt <= k && j > 0; ++cnt, j = prv[j]) {
      tar = blst = j;
      update(1, 1, n);
      if(i % 2 == 0)
        t1.push_back(j);
      else
        t2.push_back(j);
      st_inc.erase(tar);
      st_dec.erase(-tar);
    }

    if(flst != -1) {
      if(st_dec.upper_bound(-nxt[flst]) == st_dec.end())
        prv[nxt[flst]] = 0;
      else
        prv[nxt[flst]] = -(*st_dec.upper_bound(-nxt[flst]));
    }

    if(blst != -1) {
      if(st_inc.upper_bound(prv[blst]) == st_inc.end())
        nxt[prv[blst]] = n + 1;
      else
        nxt[prv[blst]] = *st_inc.upper_bound(prv[blst]);
    }
  }

  for(int i = 0; i < t1.size(); ++i)
    res[t1[i]] = 1;
  for(int i = 0; i < t2.size(); ++i)
    res[t2[i]] = 2;
  
  for(int i = 1; i <= n; ++i)
    printf("%d", res[i]);
  puts("");

  return 0;
}
