#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  
  int r1 = k * l / nl, r2 = c * d, r3 = p / np;
  cout << min(r1, min(r2, r3)) / n << endl;
  
  return 0;
}
