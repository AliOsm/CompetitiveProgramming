#include <stdio.h>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	int n, c, res, tres;
	ll tmp;
	vector<pair<int, int> > candies;
	vector<int> indxs;
	while(t-- != 0) {
		res = tres = 0;
		scanf("%d%d", &n, &c);

		candies.clear();
		candies.resize(n);
		indxs.clear();
		indxs.resize(n);

		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &candies[i].first, &candies[i].second);
			indxs[i] = i;
		}

		do {
			tres = 0;
			tmp = c;
			for(int i = 0; i < (int)indxs.size(); ++i) {
				if(tmp >= candies[indxs[i]].first) {
					tmp -= candies[indxs[i]].first;
					tmp += candies[indxs[i]].second;
					++tres;
				}
			}
			res = max(res, tres);
		} while(next_permutation(indxs.begin(), indxs.end()));

		printf("%d\n", res);
	}

	return 0;
}

