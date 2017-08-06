#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b;
vector<pair<int, int> > arr;

int main() {
	scanf("%d %d %d", &n, &a, &b);
	if(a > b)
		swap(a, b);
	arr.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		if(arr[i].first > arr[i].second)
			swap(arr[i].first, arr[i].second);
	}

	int res = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			if(i != j) {
				if(arr[i].first + arr[j].first <= a && max(arr[i].second, arr[j].second) <= b)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);

				if(arr[i].second + arr[j].second <= a && max(arr[i].first, arr[j].first) <= b)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);

				if(arr[i].first + arr[j].second <= a && max(arr[i].second, arr[j].first) <= b)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);

				if(arr[i].second + arr[j].first <= a && max(arr[i].first, arr[j].second) <= b)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);

				if(arr[i].first + arr[j].first <= b && max(arr[i].second, arr[j].second) <= a)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);

				if(arr[i].second + arr[j].second <= b && max(arr[i].first, arr[j].first) <= a)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);

				if(arr[i].first + arr[j].second <= b && max(arr[i].second, arr[j].first) <= a)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);

				if(arr[i].second + arr[j].first <= b && max(arr[i].first, arr[j].second) <= a)
					res = max(res, arr[i].first * arr[i].second + arr[j].first * arr[j].second);
			}
		}

	printf("%d\n", res);

	return 0;
}

