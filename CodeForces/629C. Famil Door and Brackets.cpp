#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

typedef long long ll;

int const MOD = 1e9 + 7;
int n, m, o, c;
string s;
int dp[2001][6001][2];

int rec(int index, int opens, bool cut) {
	if(opens < 0 || opens > 6000)
		return 0;

	if(index == n + 1)
		return opens == 0 && cut;

	int &ret = dp[index][opens][cut];
	if(ret != -1)
		return ret;
	ret = 0;

	ret = (ret + rec(index + 1, opens + 1, cut)) % MOD;
	ret = (ret + rec(index + 1, opens - 1, cut)) % MOD;
	if(!cut && opens >= c)
		ret = (ret + rec(index + 1, opens + o - c, true)) % MOD;

	return ret %= MOD;
}

int main() {
	cin >> n >> m >> s;

	if(n % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}

	for(int i = 0; i < (int)s.length(); ++i)
		s[i] == '(' ? ++o : (o > 0 ? --o : ++c);

	if(n == m) {
		if(o == 0 && c == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}

	n -= m;
	memset(dp, -1, sizeof dp);
	cout << rec(0, 0, false) << endl;

	return 0;
}

