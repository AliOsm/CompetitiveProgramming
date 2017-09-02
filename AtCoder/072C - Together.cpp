#include <stdio.h>
#include <algorithm>
 
using namespace std;

int const N = 1e5 + 5;
int n, fr[N];

int main() {
	scanf("%d", &n);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		++fr[tmp];
	}
 
	int res = fr[0] + fr[1];
	for(int i = 1; i < N - 1; ++i) {
		res = max(res, fr[i] + fr[i - 1] + fr[i + 1]);
	}
	res = max(res, fr[N] + fr[N - 1]);
 
	printf("%d\n", res);
 
    return 0;
}
