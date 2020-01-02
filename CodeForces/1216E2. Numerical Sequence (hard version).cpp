#include <bits/stdc++.h>

using namespace std;

int q;

long long digits_until_block(long long block) {
	long long tot = 0, sub = 0;
	while(sub < block) {
		tot += (block - sub) * (block + 1 - sub) / 2.0;
		sub *= 10, sub += 9;
	}
	return tot;
}

long long get_block(long long n) {
	long long l = 1, r = 1e9, mid, res;

	while(l <= r) {
		mid = (l + r) / 2;

		if(digits_until_block(mid) >= n && digits_until_block(mid - 1) < n) {
			res = mid;
			break;
		} else if(digits_until_block(mid) < n)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return res;
}

long long digits_until_number(long long number) {
	long long tot = 0, sub = 0;
	while(sub < number) {
		tot += (number - sub);
		sub *= 10;
		sub += 9;
	}
	return tot;
}

long long get_number(long long n, long long block) {
	long long l = 1, r = 1e9, mid, res;

	while(l <= r) {
		mid = (l + r) / 2;

		if(digits_until_number(mid) >= n && digits_until_number(mid - 1) < n) {
			res = mid;
			break;
		} else if(digits_until_number(mid) < n)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return res;
}

long long get_digit(long long n, long long i) {
	long long nrev = 0;
	while(n != 0) {
		nrev *= 10;
		nrev += (n % 10);
		n /= 10;
	}
	long long cnt = 0, cur = 0;
	while(cnt != i) {
		cur = nrev % 10;
		nrev /= 10;
		cnt += 1;
	}

	return cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		long long tmp;
		scanf("%lld", &tmp);
		long long block = get_block(tmp);
		tmp -= digits_until_block(block - 1);
		long long number = get_number(tmp, block);
		tmp -= digits_until_number(number - 1);
		printf("%lld\n", get_digit(number, tmp));
	}

	return 0;
}