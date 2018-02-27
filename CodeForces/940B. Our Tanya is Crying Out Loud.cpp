#include <bits/stdc++.h>

using namespace std;

long long n, k, A, B;

long long rec(long long x) {
  if(x <= 0)
    return 2e18;
  if(x == 1)
    return 0;
  
  long long tmp = x - (k * (x / k));
  if(k > x)
    return (x - 1) * A;
  
  if(x % k == 0) {
    if((x - (x / k)) * A < B)
      return rec(x / k) + (x - (x / k)) * A;
    else
      return rec(x / k) + B;
  } else
    return rec(x - tmp) + (tmp * A);
}

int main() {
  cin >> n >> k >> A >> B;
  
  if(k == 1 || k > n) {
    cout << (n - 1) * A << endl;
    return 0;
  }
  
  if(k == n) {
    cout << min(B, (n - 1) * A) << endl;
    return 0;
  }
  
  cout << rec(n) << endl;
  
  return 0;
}

