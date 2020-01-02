#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n;
char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d\n%s", &n, s);
	int len = strlen(s);

	int res = 0, a = 0, b = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'a')
			++a;
		if(s[i] == 'b')
			++b;
		if((i + 1) % 2 == 0 && a != b) {
			++res;
			if(a > b) {
				if(s[i] == 'a')
					s[i] = 'b';
				else
					s[i - 1] = 'b';
				--a, ++b;
			} else {
				if(s[i] == 'b')
					s[i] = 'a';
				else
					s[i - 1] = 'a';
				--b, ++a;
			}
		}
	}

	printf("%d\n", res);
	printf("%s\n", s);

	return 0;
}