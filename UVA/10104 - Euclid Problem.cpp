#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int a, b, x, y, gcd;

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
  while(scanf("%d %d", &a, &b) != EOF) {
    _gcd(a, b);
    printf("%d %d %d\n", x, y, gcd);
  }
  
  return 0;
}
