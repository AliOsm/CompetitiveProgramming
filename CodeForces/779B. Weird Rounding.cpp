#include <stdio.h>
#include <string.h>

using namespace std;

int k;
char s[11];

int main() {
	scanf("%s %d", s, &k);

	int len = strlen(s);
	int res = 0, del = 0;
	for(int i = len - 1; i >= 0; --i) {
		if(s[i] == '0')
			++res;
		else
			++del;
		if(res == k)
			break;
	}

	if(res == k)
		printf("%d\n", del);
	else
		printf("%d\n", len - 1);

    return 0;
}
