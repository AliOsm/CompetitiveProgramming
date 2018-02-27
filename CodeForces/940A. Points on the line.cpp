#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d, a[101];
  
  cin >> n >> d;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  
  int l = 0, r = 0, res = 0;
  while(r < n) {
    res = max(res, r - l + 1);
    ++r;
    while(l < r && a[r] - a[l] > d)
      ++l;
  }
  
  cout << n - res << endl;
  
  return 0;
}

