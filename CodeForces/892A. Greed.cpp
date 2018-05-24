/*
  Idea:
    - Sorting.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], b[N];

int main() {
  cin >> n;
  long long tot = 0;
  for(int i = 0, tmp; i < n; ++i)
  	cin >> tmp, tot += tmp;
  for(int i = 0; i < n; ++i)
  	cin >> b[i];
  sort(b, b + n);
  reverse(b, b + n);

  if(tot <= 1ll * b[0] + b[1])
  	cout << "YES" << endl;
  else
  	cout << "NO" << endl;

  return 0;
}
