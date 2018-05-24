/*
  Idea:
    - Sort and shift as the tutorial says :3
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 22;
int n, a[N], b[N], tmp[N];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> a[i], tmp[i] = a[i];
  sort(tmp, tmp + n);

  for(int i = 0; i < n; ++i) {
  	int idx = upper_bound(tmp, tmp + n, a[i]) - tmp;
  	if(idx == n)
  		idx = 0;
  	b[i] = tmp[idx];
  }

  for(int i = 0; i < n; ++i)
  	cout << b[i] << ' ';
  cout << endl;

  return 0;
}
