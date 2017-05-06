#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
vector<pair<long long, long long> > stu, pnt;
 
int main() {
  int n, m;
  cin >> n >> m;
  
  int a, b;
  
  while(n--) {
    cin >> a >> b;
    stu.push_back({a, b});
  }
  n = stu.size();
  
  while(m--) {
    cin >> a >> b;
    pnt.push_back({a, b});
  }
  m = pnt.size();
  
  long long res;
  int indx;
  
  for(int i = 0; i < n; i++) {
    res = 1e18;
    
    for(int j = 0; j < m; j++) {
      if(abs(stu[i].first - pnt[j].first) + abs(stu[i].second - pnt[j].second) < res) {
        res = abs(stu[i].first - pnt[j].first) + abs(stu[i].second - pnt[j].second);
        indx = j;
      }
    }
    
    cout << indx + 1 << endl;
  }
  
  return 0;
}
