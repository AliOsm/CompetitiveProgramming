/*
	Idea:
		- The grammar is a context free grammar, so we can use recursive function
			to solve it.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
bool error;
char s[N];
int n, cur, len;

int expression();
int component();
int factor();

int expression() {
	if(error)
		return 0;

	int ret = component();

	while(cur < len && s[cur] == '+')
		++cur, ret += component();

	if(cur != len && s[cur] != '*' && s[cur] != ')')
		error = true;

	return ret;
}

int component() {
	if(error)
		return 0;

	int ret = factor();

	while(cur < len && s[cur] == '*')
		++cur, ret *= component();

	if(cur != len && s[cur] != '+' && s[cur] != ')')
		error = true;

	return ret;
}

int factor() {
	if(error)
		return 0;

	bool ok = false;
	int ret = -1, tmp = 0;

	while(cur < len && isdigit(s[cur])) {
		ok = true;
		tmp *= 10, tmp += s[cur] - '0', ++cur;
	}

	if(ok)
		ret = tmp;

	if(!ok && s[cur] == '(') {
		++cur, ret = expression();
		if(s[cur] != ')')
			error = true;
		++cur;
	} else if(!ok)
		error = true;

	return ret;
}

int main() {
	scanf("%d", &n);
	while(n-- != 0) {
		scanf("%s", s);
		len = strlen(s);

		error = cur = 0;

		int res = expression();

		if(cur != len)
			error = true;

		if(error)
			puts("ERROR");
		else
			printf("%d\n", res);
	}

	return 0;
}
