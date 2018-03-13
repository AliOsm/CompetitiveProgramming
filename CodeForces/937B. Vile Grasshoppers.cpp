#include <bits/stdc++.h>

using namespace std;

bool divisors(int x, int p) {
  int sqrtx = sqrt(x);
  for(int i = 1; i <= sqrtx; ++i) {
    if(x % i == 0) {
      if(i != 1 && i <= p)
        return false;
      
      if(x / i != 1 && x / i <= p)
        return false;
    }
  }
  return true;
}

int main() {
  int p, y;
  cin >> p >> y;
  
  for(int i = y; i > p && i >= y - 500; --i) {
    if(divisors(i, p)) {
      cout << i << endl;
      return 0;
    }
  }
  
  cout << -1 << endl;
  
  return 0;
}
