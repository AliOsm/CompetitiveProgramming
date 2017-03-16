#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, m, res, tmp, cycle, x, y;
  
  while(cin >> n >> m) {
    x = n;
    y = m;
    
    if(n > m) {
      tmp = n;
      n = m;
      m = tmp;
    }
    
    res = 0;
    
    for(int i = n; i <= m; i++) {
      tmp = i;
      
      cycle = 0;
      while(tmp != 1) {
        cycle++;
        if(tmp % 2 == 0) tmp /= 2;
        else tmp = tmp * 3 + 1;
      }
      cycle++;
      
      res = max(res, cycle);
    }
    
    cout << x << ' ' << y << ' ' << res << endl;
  }
  
  return 0;
}

