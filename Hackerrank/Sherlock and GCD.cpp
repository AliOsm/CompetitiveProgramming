/*
  Idea:
    - If the GCD of all elements in the array is 1 then there is a subset of
      elements and the answer is YES, otherwise is NO.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int t, n, a[N];

int main() {
  cin >> t;
  while(t-- != 0) {
  	cin >> n;
  	int gcd = 0;
  	for(int i = 0; i < n; ++i) {
  		cin >> a[i];
  		gcd = __gcd(a[i], gcd);
  	}

  	if(gcd == 1)
  		cout << "YES" << endl;
  	else
  		cout << "NO" << endl;
  }

  return 0;
}
