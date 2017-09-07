#include <bits/stdc++.h>

using namespace std;

int n, m;

long long power(long long a, int p) {
	if(p == 0)
		return 1;

	long long res = power(a, p >> 1) % m;
	res = (res * res) % m;

	if(p & 1)
		res = (res * a) % m;

	return res;
}

int main() {
	scanf("%d %d", &n, &m);

	long long lst = power(3, n) - 1;
	if(lst >= 0)
		printf("%lld\n", lst);
	else
		printf("%lld\n", lst + m);

	return 0;
}
