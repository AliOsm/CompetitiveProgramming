#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int t, xx, k, x, y, gcd;

void _gcd(int a, int b) {
	if(b == 0) {
		gcd = a;
		x = 1;
		y = 0;
		return;
	}
	_gcd(b, a % b);
	ll x0 = y;
	ll y0 = x - (a / b) * y;
	x = x0;
	y = y0;
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d", &xx, &k);
    _gcd(xx / k, ceil(1.0 * xx / k));
    x *= xx/gcd;
    y *= xx/gcd;
    printf("%d %d\n", x, y);
  }
  
  return 0;
}
