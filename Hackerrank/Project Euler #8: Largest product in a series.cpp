#include <stdio.h>
#include <algorithm>

using namespace std;

char s[1001];

int main() {
	int t, n, k, tmp, res;
	scanf("%d", &t);
	while(t-- != 0) {
		res = 0;
		scanf("%d %d\n%s", &n, &k, s);
		for(int i = 0; i < n - k; ++i) {
			tmp = 1;
			for(int j = i; j < i + k; ++j)
				tmp *= (s[j] - '0');
			res = max(res, tmp);
		}
		printf("%d\n", res);
	}

    return 0;
}

