/*
	Idea:
		- Greedy with Binary search.
		- Greedily we can choose some bells and put them alone in some boxes.
		- Then we can do binary search on the other bells to find the smallest
			box size.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, k, a[N];

bool can(int mid) {
	int have = k;
	for(int i = 0, j = n - 1; i <= j; ++i, --j) {
		if(i == j) {
			if(a[i] > mid)
				return false;
			--have;
			break;
		} else {
			if(a[i] + a[j] <= mid)
				--have;
			else {
				for(int k = i; k <= j; ++k) {
					if(k + 1 <= j && a[k] + a[k + 1] <= mid) {
						++k, --have;
						continue;
					}
					if(a[k] > mid)
						return false;
					--have;
				}
				break;
			}
		}
	}
	return have >= 0;
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
  	cin >> a[i];

  if(k >= n) {
  	cout << a[n - 1] << endl;
  	return 0;
  }

  int rem = (k * 2) - n;
  n -= rem, k -= rem;

  int l = 1, r = 3000000, mid, res = -1;
  while(l <= r) {
  	mid = (l + r) / 2;
  	if(can(mid))
  		res = mid, r = mid - 1;
  	else
  		l = mid + 1;
  }

  cout << max(res, a[n + rem - 1]) << endl;

  return 0;
}
