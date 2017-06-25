#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int a[3001], n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	if(n <= 2) {
		puts("no");
		return 0;
	}

	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < n - 1; ++j) {
			if((min(a[i], a[i+1]) < min(a[j], a[j+1]) && min(a[j], a[j+1]) < max(a[i], a[i+1]) && max(a[i], a[i+1]) < max(a[j], a[j+1])) ||
			   (min(a[j], a[j+1]) < min(a[i], a[i+1]) && min(a[i], a[i+1]) < max(a[j], a[j+1]) && max(a[j], a[j+1]) < max(a[i], a[i+1]))) {
				puts("yes");
				return 0;
			}
		}
	}

	puts("no");

	return 0;
}

