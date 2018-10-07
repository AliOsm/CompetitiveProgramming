#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct Points{
  int x, y;
  Points() {};
  Points(int xx, int yy){
    x = xx, y = yy;
  }
};

int const N = 1000 + 1;
int t, color[N];
vector<int> ww[N];
vector<pair<Points, int> > vi, wm;

double dist(int i , int j){
  ll dx = vi[i].first.x - vi[j].first.x;
  ll dy = vi[i].first.y - vi[j].first.y;
  return sqrt(dx * dx + dy * dy);
}

bool check(int xx, int w){
  wm.clear();
  for(int i = 0; i < ww[xx].size(); ++i)
    wm.push_back(vi[ww[xx][i]]);
  ll mx = 0, mn = 1LL * 2e9;
  for(int i = 0; i < wm.size(); ++i){
    mx = max(mx, 0LL + wm[i].first.x + wm[i].second);
    mn = min(mn, 0LL + wm[i].first.x - wm[i].second);
  }
  if(mx >= w && mn <= 0)
    return true;
  return false;
}

int find(int x) {
  return x == color[x] ? x : color[x] = find(color[x]);
}

int main() {
  scanf("%d", &t);
  while(t--) {
    vi.clear();
    for(int i = 0; i < N; ++i)
      ww[i].clear();
    int n, w, l;
    cin >> n >> w >> l;
    for(int i = 0; i < n; ++i) {
      int x, y, r;
      cin >> x >> y >> r;
      Points t(x, y);
      vi.push_back(make_pair(t, r));
    }
    for(int i = 0; i < n; ++i)
      color[i] = i;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == j)
          continue;
        if(dist(i, j) <= vi[i].second + vi[j].second || 
          dist(i, j) <= vi[i].second || 
          dist(i, j) <= vi[j].second){
          int ii = find(i);
          int jj = find(j);
          if(ii == jj)
            continue;
          color[ii] = jj;
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
      color[i] = find(i);
    for(int i = 0; i < n; ++i)
      ww[color[i]].push_back(i);
    for(int i = 0; i < n; ++i) {
      if(ww[i].size() == 0)
        continue;
      if(check(i, w))
        ++ans;
    }
    cout << ans << endl;
  }

  return 0;
}
