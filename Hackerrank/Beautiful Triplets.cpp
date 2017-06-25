#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

int n, d, a[10001], res;
vector<int> mid;

int main() {
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			if(a[j] - a[i] == d)
				mid.push_back(j);

	res = 0;
	for(int j = 0; j < (int)mid.size(); ++j)
		for(int k = mid[j] + 1; k < n; ++k)
			if(a[k] - a[mid[j]] == d)
				++res;

	printf("%d\n", res);
}

