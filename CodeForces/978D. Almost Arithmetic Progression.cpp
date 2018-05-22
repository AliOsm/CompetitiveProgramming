/*
  Idea:
    - Brute force.
    - The first two elements in any arithmetic progression identify its factor,
      so if we try the all possibilities for the first two elements and count
      the number of changes each time and take the minimum we will get the
      right answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], b[N];

int check(int chn) {
	for(int i = 0; i < n; ++i)
		b[i] = a[i];

	int fac = b[1] - b[0];
	for(int i = 2; i < n; ++i) {
		if(b[i] - b[i-1] == fac)
			continue;
		if((b[i] - 1) - b[i-1] == fac) {
			--b[i];
			++chn;
			continue;
		}
		if((b[i] + 1) - b[i-1] == fac) {
			++b[i];
			++chn;
			continue;
		}
		return 1e9;
	}

	return chn;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> a[i];

  if(n <= 2) {
  	cout << 0 << endl;
  	return 0;
  }

  int res = 1e9;
  res = check(0);                                         // .. ..
  ++a[0], ++a[1];res = min(res, check(2));--a[0], --a[1]; // ++ ++
  --a[0], --a[1];res = min(res, check(2));++a[0], ++a[1]; // -- --
  ++a[0];res = min(res, check(1));--a[0];                 // ++ ..
  ++a[1];res = min(res, check(1));--a[1];                 // .. ++
  --a[0];res = min(res, check(1));++a[0];                 // -- ..
  --a[1];res = min(res, check(1));++a[1];                 // .. --
  --a[0], ++a[1];res = min(res, check(2));++a[0], --a[1]; // -- ++
  ++a[0], --a[1];res = min(res, check(2));--a[0], ++a[1]; // ++ --

  if(res == 1e9)
  	cout << -1 << endl;
  else
  	cout << res << endl;

  return 0;
}
