#include <bits/stdc++.h>

using namespace std;

long long const oo = 1e15 + 1;
long long l, r;
vector<long long> all;

void rec(long long num) {
	if(num > oo)
		return;

	all.push_back(num);
	rec(num * 10 + 4);
	rec(num * 10 + 7);
}

int main() {
	rec(4);
	rec(7);
	sort(all.begin(), all.end());

	scanf("%lld %lld", &l, &r);

	long long res = 0;
	for(long long i = l; i <= r;) {
		long long v = *lower_bound(all.begin(), all.end(), i);
		if(v > r)
			res += (r - i + 1) * v;
		else
			res += (v - i + 1) * v;
		i = v + 1;
	}
	printf("%lld\n", res);

	return 0;
}

