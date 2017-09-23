#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
char s[N];

int main() {
	scanf("%s", s);

	int len = strlen(s), idx = -1;
	for(int i = 0; i < len; ++i)
		if(s[i] != 'a') {
			idx = i;
			break;
		}

	if(idx == -1) {
		s[len - 1] = 'z';
		puts(s);
		return 0;
	}

	while(idx < len && s[idx] != 'a') {
		s[idx] = char(int(s[idx]) - 1);
		++idx;
	}
	puts(s);

	return 0;
}

