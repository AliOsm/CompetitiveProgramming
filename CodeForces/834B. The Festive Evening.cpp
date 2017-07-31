#include <stdio.h>

using namespace std;

typedef long long ll;

int freq[26];
bool vis[26];

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	for(int i = 0; i < s.length(); ++i)
		++freq[s[i] - 'A'];

	int guards = 0;
	for(int i = 0; i < s.length(); ++i) {
		if(!vis[s[i] - 'A']) {
			++guards;
			vis[s[i] - 'A'] = true;
		}

		if(guards > k) {
			puts("YES");
			return 0;
		}

		if(--freq[s[i] - 'A'] == 0) {
			--guards;
			vis[s[i] - 'A'] = false;
		}
	}

	puts("NO");

	return 0;
}
