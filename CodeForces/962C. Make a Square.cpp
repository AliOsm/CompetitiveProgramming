#include <bits/stdc++.h>

using namespace std;

int n, all[15], len;
long long s[1000000];

int rec(int idx, long long num, bool tak, int cnt) {
	if(idx == len) {
		if(tak && s[int(sqrt(num))] == num)
			return len - cnt;
		return 1e9;
	}

	if(all[idx] == 0 && !tak)
		return rec(idx + 1, num, tak, cnt);

	return min(rec(idx + 1, num, tak, cnt), rec(idx + 1, num * 10 + all[idx], true, cnt + 1));
}

int main() {
	for(int i = 0; i < 1000000; ++i)
		s[i] = 1ll * i * i;

	cin >> n;

	len = log10(n) + 1;
	for(int i = len - 1; i >= 0; --i) {
		all[i] = n % 10;
		n /= 10;
	}

	int res = rec(0, 0, false, 0);

	if(res == 1e9)
		cout << -1 << endl;
	else
		cout << res << endl;

  return 0;
}
