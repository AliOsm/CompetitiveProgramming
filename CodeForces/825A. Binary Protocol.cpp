#include <stdio.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	char s[101];
	scanf("%s", s);

	for(int i = 0, cnt = 0; s[i] != '\0'; ++i) {
		while(s[i] != '\0' && s[i] == '0')
			++cnt, ++i;
		if(cnt > 1)
			for(int j = 0; j < cnt - 1; ++j)
				putchar('0');

		cnt = 0;

		while(s[i] != '\0' && s[i] == '1')
			++cnt, ++i;
		--i;
		printf("%d", cnt);

		cnt = 0;
	}
	puts("");

	return 0;
}
