#include <iostream>

using namespace std;

long long n, m;

int main() {
  cin >> n >> m;
  
  if(m >= n) {
    cout << n << endl;
    return 0;
  }
  
  n -= m;
  long long l = 0, r = 1e10, mid, res = 0;
  while(l <= r) {
    mid = (l+r)/2;
    
    if(n <= mid * (mid + 1) / 2) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  
  cout << m + res << endl;

  return 0;
}

