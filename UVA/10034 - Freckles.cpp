#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct edge;

int const N = 101;
int n, ds[N];
vector<pair<double, double> > points;
vector<edge> e;

struct edge {
  double dist;
  int from, to;
  
  edge(int from, int to) {
    this->from = from;
    this->to = to;
    this->dist = sqrt(pow(points[from].first - points[to].first, 2.0) + pow(points[from].second - points[to].second, 2.0));
  }
  
  bool operator<(const edge &e) const {
      return dist < e.dist;
  }
};

int find(int x) {
  return ds[x] == x ? x : ds[x] = find(ds[x]);
}

int main() {
  bool blankline = false;
  
  int t;
  cin >> t;
  
  double a, b, res;
  int take, u, v;
  while(t--) {
    if(blankline) cout << endl;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
      ds[i] = i;
    points.clear();
    e.clear();
    res = take = 0;
    
    while(n--) {
      cin >> a >> b;
      points.push_back({a, b});
    }
    n = points.size();
    
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        e.push_back(edge(i, j));
    sort(e.begin(), e.end());
    
    for(int i = 0; i < e.size() && take < n - 1; i++) {
      u = find(e[i].from);
      v = find(e[i].to);
      
      if(u != v) {
        take++;
        res += e[i].dist;
        ds[u] = v;
      }
    }
    
    cout << fixed << setprecision(2) << res << endl;
    
    blankline = true;
  }
  
  return 0;
}

