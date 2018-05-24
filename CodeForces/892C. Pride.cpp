/*
  Idea:
    - Greedy.
    - If there is one 1 in the array then the answer is `n - 1`.
    - If there is no odd number in the array then the answer is `-1`.
    - Else try from each index i to find the shortest consequtive subarray
      such that the GCD of it equal to 1, then the answer will be the `length
      of the subarray + n - 1`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int n, a[N];

int main() {
  bool even = true;
  int one = 0;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
  	scanf("%d", a + i);
  	one += a[i] == 1;
  	if(a[i] & 1)
  		even = false;
  }

  if(one > 0) {
  	cout << n - one << endl;
  	return 0;
  }

  if(even) {
  	cout << -1 << endl;
  	return 0;
  }

  int mn = 1e9;
  for(int i = 0; i < n; ++i) {
  	int gcd = a[i];
  	for(int j = i + 1; j < n; ++j) {
  		gcd = __gcd(gcd, a[j]);
  		if(gcd == 1) {
  			mn = min(mn, j - i);
  			break;
  		}
  	}
  }

  if(mn == 1e9)
  	cout << -1 << endl;
  else
  	printf("%d\n", mn + n - 1);

  return 0;
}
