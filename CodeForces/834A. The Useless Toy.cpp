#include <stdio.h>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	char s, e;
	scanf(" %c %c", &s, &e);
	int n;
	scanf("%d", &n);

	n %= 4;

	string tmp1 = "^>v<^>v<";
	bool cw = false, ccw = false;

	if(tmp1.find(s) + n < tmp1.size() && tmp1[tmp1.find(s) + n] == e)
		cw = true;
	if(tmp1.find(s, 3) - n >= 0 && tmp1[tmp1.find(s, 3) - n] == e)
		ccw = true;

	if(cw && ccw)
		puts("undefined");
	else {
		if(cw)
			puts("cw");
		else if(ccw)
			puts("ccw");
		else
			puts("undefined");
	}

	return 0;
}
