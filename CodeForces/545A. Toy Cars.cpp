#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[101][101], col[101];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(a[i][j] == 1)
				++col[i];
			else if(a[i][j] == 2)
				++col[j];
			else if(a[i][j] == 3)
				++col[i], ++col[j];

	int cnt = 0;
	for(int i = 0; i < n; ++i)
		if(col[i] == 0)
			++cnt;

	printf("%d\n", cnt);

	for(int i = 0; i < n; ++i)
		if(col[i] == 0)
			printf("%d ", i + 1);
}
