#include <bits/stdc++.h>

using namespace std;

int const N = 4e5 + 1;
int t, n, a[N], freq[N];
vector<int> all;

int main() {
	scanf("%d", &t);
	
	while (t-- != 0) {
		all.clear();
		memset(freq, 0, sizeof freq);

		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			all.push_back(a[i]);
		}
		
		sort(a, a + n);
		
		for(int i = 0; i < n - 1; ++i) {
		    if(a[i + 1] - a[i] <= 1) {
		        continue;
		    }
		    
		    all.push_back(a[i] + 1);
		}

		sort(all.begin(), all.end());
		all.resize(unique(all.begin(), all.end()) - all.begin());

        int mx = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
			++freq[a[i]];
			mx = max(mx, a[i]);
		}
		
		long long res = 0, diff;
		for (int i = 0; i < mx + 1; ++i) {
			if (freq[i] == 0) {
				continue;
			}

			res += freq[i];

			while (i < N - 1 && freq[i] != 0) {
				while (i < N - 1 && freq[i + 1] >= freq[i]) {
					res += freq[i + 1] - freq[i];
					++i;
				}

				while (i < N - 1 && freq[i] > freq[i + 1]) {
					++i;
				}

				if (freq[i] == 0) {
					break;
				}
			}
		}

        printf("%d\n", res);
	}

	return 0;
}
