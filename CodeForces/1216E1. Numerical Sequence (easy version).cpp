#include <bits/stdc++.h>

using namespace std;

int const N = 1e6;
int q;
long long cm1[N];
long long cm2[N];

int get_digit(int n, int i) {
	int nrev = 0;
	while(n != 0) {
		nrev *= 10;
		nrev += (n % 10);
		n /= 10;
	}
	int cnt = 0, cur = 0;
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

	cm1[0] = cm2[0] = 0;
	for(int i = 1; i < N; ++i)
		cm1[i] = floor(log10(i)) + 1;
	cm2[1] = 1;
	for(int i = 2; i < N; ++i)
		cm1[i] += cm1[i - 1], cm2[i] = cm1[i];
	for(int i = 2; i < N; ++i)
		cm2[i] += cm2[i - 1];

	scanf("%d", &q);
	for(int i = 0, tmp; i < q; ++i) {
		scanf("%d", &tmp);
		int idx = lower_bound(cm2 + 1, cm2 + N, tmp) - cm2;
		tmp -= cm2[idx - 1];
		idx = lower_bound(cm1 + 1, cm1 + N, tmp) - cm1;
		printf("%d\n", get_digit(idx, tmp - cm1[idx - 1]));
	}

	return 0;
}