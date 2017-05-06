#include <stdio.h>
#include <vector>
#include <math.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 51;
int n, m, k, match[N];
bool vis[N];
vector<pair<double, double> > a, b;

double dist(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(a.first - b.first, 2.0) + pow(a.second - b.second, 2.0));
}

bool findMatch(int i, double mid) {
  vis[i] = true;
  
  for(int j = 0; j < m; ++j)
    if(dist(a[i], b[j]) <= mid && (match[j] == -1 || (!vis[match[j]] && findMatch(match[j], mid)))) {
      match[j] = i;
      return true;
    }
  
  return false;
}

bool can(double mid) {
  int res = n;
  
  memset(match, -1, sizeof match);
  for(int i = 0; i < n; ++i) {
    memset(vis, false, sizeof vis);
    if(findMatch(i, mid))
      --res;
  }
  
  return res <= k;
}

int main() {
  int t;
  scanf("%d", &t);
  
  double l, r, mid, res;
  for(int kase = 1; t--; ++kase) {
    scanf("%d%d%d", &n, &m, &k);
    
    a.clear(); b.clear();
    a.resize(n); b.resize(m);
    
    for(int i = 0; i < n; ++i)
      scanf("%lf%lf", &a[i].first, &a[i].second);
    for(int i = 0; i < m; ++i)
      scanf("%lf%lf", &b[i].first, &b[i].second);
    
    if((n == 0 && m == 0) || n == 0 || n == k) {
      printf("Case #%d:\n0.000\n\n", kase);
      continue;
    }
    
    l = 0, r = 1e9;
    res = -1;
    for(int i = 0; i < 50; ++i) {
      mid = (l + r) / 2;
      if(can(mid)) {
        res = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    
    if(res == -1) printf("Case #%d:\nToo bad.\n\n", kase);
    else printf("Case #%d:\n%.3lf\n\n", kase, res);
  }
  
  return 0;
}

