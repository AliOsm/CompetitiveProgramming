/*
  Idea:
    - Brute force.
    - Try any 3 combination of divisors of `n` to construct A, B and C.
*/

#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> d;

void divisors(long long x) {
  d.clear();
  int sqrtx = sqrt(x);
  for(int i = 1; i <= sqrtx + 1; ++i)
    if(x % i == 0) {
      d.push_back(i);

      if(x / i != i)
        d.push_back(x / i);
    }
  sort(d.begin(), d.end());
}

int main() {
  cin >> n;
  divisors(n);

  long long mn = 2e18, mx = -2e18;
  for(int i = 0; i < d.size(); ++i)
    for(int j = i; j < d.size(); ++j)
      if(n % (d[i] * d[j]) == 0) {
        long long k = n / (d[i] * d[j]);

        mn = min(mn, (d[i] + 1) * (d[j] + 2) * (k + 2) - n);
        mx = max(mx, (d[i] + 1) * (d[j] + 2) * (k + 2) - n);

        mn = min(mn, (d[i] + 2) * (d[j] + 1) * (k + 2) - n);
        mx = max(mx, (d[i] + 2) * (d[j] + 1) * (k + 2) - n);

        mn = min(mn, (d[i] + 2) * (d[j] + 2) * (k + 1) - n);
        mx = max(mx, (d[i] + 2) * (d[j] + 2) * (k + 1) - n);
      }

  cout << mn << ' ' << mx << endl;

  return 0;
}
