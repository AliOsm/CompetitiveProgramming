#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
	int n, k, mn = 2e9 + 1;
	scanf("%d%d", &n, &k);

	arr.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		mn = min(mn, arr[i]);
	}

	long long res = 0;
	for(int i = 0; i < n; i++) {
		res += (arr[i] - mn) / k;
		if((arr[i] - mn) % k != 0) {
			puts("-1");
			return 0;
		}
	}

	printf("%lld\n", res);

  return 0;
}

