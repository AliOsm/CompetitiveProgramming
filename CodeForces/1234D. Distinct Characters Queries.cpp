#include <bits/stdc++.h>

using namespace std;

char c;
int q, ssqrt, t, pos, l, r;
string s;
vector<vector<int> > buckets;

void build() {
	for(int i = 0, j; i < s.length(); i += ssqrt) {
		j = i;
		vector<int> fr;
		for(int j = 0; j < 26; ++j)
			fr.push_back(0);
		while(j < s.length() && j < i + ssqrt)
			++fr[s[j++] - 'a'];
		buckets.push_back(fr);
	}
}

void update() {
	int bucket = (pos + ssqrt - 1) / ssqrt - 1;
	--buckets[bucket][s[pos - 1] - 'a'];
	s[pos - 1] = c;
	++buckets[bucket][s[pos - 1] - 'a'];
}

int get() {
	int lbucket = (l + ssqrt - 1) / ssqrt - 1 + 1;
	int rbucket = (r + ssqrt - 1) / ssqrt - 1 - 1;

	bool exist[26] = {false};
	if(lbucket < rbucket) {
		for(int i = lbucket; i <= rbucket; ++i)
			for(int j = 0; j < 26; ++j)
				exist[j] |= buckets[i][j] > 0;
		for(int i = l - 1; i < ssqrt * lbucket; ++i)
			exist[s[i] - 'a'] = true;
		for(int i = ssqrt * rbucket + ssqrt; i < r; ++i)
			exist[s[i] - 'a'] = true;
	} else {
		for(int i = l - 1; i < r; ++i)
			exist[s[i] - 'a'] = true;
	}

	int res = 0;
	for(int i = 0; i < 26; ++i)
		res += exist[i];
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	cin >> s;
	ssqrt = sqrt(s.length());
	build();
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		scanf("%d", &t);
		if(t == 1) {
			scanf("%d %c", &pos, &c);
			update();
		} else {
			scanf("%d %d", &l, &r);
			printf("%d\n", get());
		}
	}

	return 0;
}