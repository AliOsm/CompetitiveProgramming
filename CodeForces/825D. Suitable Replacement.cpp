#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int const N = 1e6 + 1;
int freqs[26], freqt[26], freqn[26];
char s[N], t[N];
vector<int> idx;

bool can(int mid) {
	long long need = 0;
	for(int i = 0; i < 26; ++i)
		need += max(0LL, 1LL * freqt[i] * mid - freqs[i]);
	return need <= (int)idx.size();
}

int main() {
	scanf("%s %s", s, t);

	for(int i = 0; s[i] != '\0'; ++i)
		if(s[i] != '?')
			++freqs[s[i] - 'a'];
		else if(s[i] == '?')
			idx.push_back(i);

	for(int i = 0; t[i] != '\0'; ++i)
		++freqt[t[i] - 'a'];

	int l = 0, r = 1e9, res = 0, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(can(mid)) {
			res = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}

	for(int i = 0; i < 26; ++i) {
		long long add = max(0LL, 1LL * res * freqt[i] - freqs[i]);
		while(add--) {
			s[idx.back()] = i + 'a';
			idx.pop_back();
		}
	}

	while(!idx.empty()) {
		s[idx.back()] = 'a';
		idx.pop_back();
	}

	printf("%s\n", s);

	return 0;
}

