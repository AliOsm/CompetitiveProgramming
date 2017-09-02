#include <stdio.h>
 
using namespace std;

int const N = 1e5 + 5;
int n, a[N];
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
 
	int res = 0;
 
	if(a[1] == 1) {
		swap(a[1], a[2]);
		++res;
	}
 
	for(int i = 2; i < n; ++i) {
		if(a[i] == i) {
			swap(a[i], a[i + 1]);
			--i;
			++res;
		}
	}
 
	if(a[n] == n) {
		swap(a[n], a[n - 1]);
		++res;
	}
 
	printf("%d\n", res);
 
    return 0;
}
