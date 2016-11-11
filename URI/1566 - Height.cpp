#include <stdio.h>
#include <algorithm>

using namespace std;

unsigned char arr[3000001];

int main() {
	int t;
	scanf("%i", &t);

	while (t--) {
		int n;
		scanf("%i", &n);
		
		for(int i = 0; i < n; i++) scanf("%i", &arr[i]);
		sort(arr, arr + n);
		for(int i = 0; i < n; i++) {
			printf("%i", arr[i]);
			i + 1 != n ? printf(" ") : NULL;
		}
		
		puts("");
	}

	return 0;
}
