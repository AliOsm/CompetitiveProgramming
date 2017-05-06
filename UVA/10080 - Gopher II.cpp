#include <stdio.h>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int const N = 101;
int n, m, s, v, match[N];
bool vis[N];
vector<pair<double, double> > a, b;

double dist(pair<double, double> p1, pair<double, double> p2) {
  return sqrt(pow(p1.first - p2.first, 2.0) + pow(p1.second - p2.second, 2.0));
}

bool findMatch(int i) {
  vis[i] = true;
  
  for(int j = 0; j < m; ++j)
    if(1.0 * dist(a[i], b[j]) / v <= s && (match[j] == -1 || (!vis[match[j]] && findMatch(match[j])))) {
      match[j] = i;
      return true;
    }
  
  return false;
}

int main() {
  while(scanf("%d%d%d%d", &n, &m, &s, &v) != EOF) {
    a.clear();
    b.clear();
    a.resize(n);
    b.resize(m);
    
    for(int i = 0; i < n; ++i)
      scanf("%lf%lf", &a[i].first, &a[i].second);
    for(int i = 0; i < m; ++i)
      scanf("%lf%lf", &b[i].first, &b[i].second);
    
    int res = 0;
    memset(match, -1, sizeof match);
    for(int i = 0; i < n; ++i) {
      memset(vis, false, sizeof vis);
      
      if(findMatch(i))
        ++res;
    }
    
    printf("%d\n", n - res);
  }
  
  return 0;
}

