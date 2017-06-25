#include <stdio.h>
#include <math.h>

using namespace std;

int divisors(int x) {
	int sqrtx = sqrt(x), res = 0;
	for(int i = 1; i <= sqrtx; ++i)
		if(x % i == 0) {
			++res;

			if(x / i != i)
				++res;
		}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	int l, r, n, res, tmp;
	while(t-- != 0) {
		scanf("%d %d", &l ,&r);
		res = 0;
		for(int i = l; i <= r; ++i) {
			tmp = divisors(i);
			if(res < tmp) {
				res = tmp;
				n = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, n, res);
	}

    return 0;
}

