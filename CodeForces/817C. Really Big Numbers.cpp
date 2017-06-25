#include <stdio.h>

using namespace std;

long long n, k;

bool can(long long mid) {
	long long tmp = mid, digits_sum = 0;
	while(tmp) {
		digits_sum += tmp % 10;
		tmp /= 10;
	}
	return mid - digits_sum >= k;
}

int main() {
	scanf("%lld %lld", &n, &k);

	long long l = 1, r = n, mid, res = -1;
	while(l <= r) {
		mid = (l + r) / 2;
		if(can(mid)) {
			r = mid - 1;
			res = mid;
		} else
			l = mid + 1;
	}

	if(res == -1) puts("0");
	else printf("%lld\n", n - res + 1);

    return 0;
}
