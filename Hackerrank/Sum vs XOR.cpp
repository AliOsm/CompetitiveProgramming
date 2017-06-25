#include <stdio.h>
#include <math.h>
#include <bitset>

typedef long long ll;

using namespace std;

ll n;

int main() {
	scanf("%lld", &n);
	bitset<65> b(n);
	ll res = 0;
	for(int i = 0, len = log2(n) + 1; i < len; ++i)
		if(b[i] == 0)
			++res;
	printf("%lld\n", 1LL * 1 << res);

    return 0;
}

