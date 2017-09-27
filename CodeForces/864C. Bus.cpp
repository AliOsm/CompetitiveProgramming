#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
int a, b, f, k;

int main() {
	scanf("%d %d %d %d", &a, &b, &f, &k);
	int tmpb = b;

	int res = 0;
	for(int i = 0; i < k; ++i) {
		if(b < 0) {
			puts("-1");
			return 0;
		}

		if(i % 2 == 0) {
			b -= f;
			if(b < 0) {
				puts("-1");
				return 0;
			}

			if(i == k - 1) {
				if((a - f) > b) {
					b = tmpb;
					++res;
				}
			} else {
				if((a - f) * 2 > b) {
					b = tmpb;
					++res;
				}
			}

			b -= (a - f);
		} else {
			b -= (a - f);
			if(b < 0) {
				puts("-1");
				return 0;
			}

			if(i == k - 1) {
				if(f > b) {
					b = tmpb;
					++res;
				}
			} else {
				if(f * 2 > b) {
					b = tmpb;
					++res;
				}
			}

			b -= f;
		}
	}

	if(b < 0) {
		puts("-1");
		return 0;
	}

	printf("%d\n", res);

	return 0;
}
