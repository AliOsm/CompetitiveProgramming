#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> a[i];
  a[n] = -1;

  int lst = a[0], res = 0;
  for(int i = 0, tmp; i < n; ++i) {
  	tmp = i;
  	while(a[i] <= a[i + 1])
  		++i;
  	res = max(res, i - tmp + 1);
  }

  cout << res << endl;

  return 0;
}
