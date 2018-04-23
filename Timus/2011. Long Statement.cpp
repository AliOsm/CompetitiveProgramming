#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, a[N];

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);

	int res = 0;
	do {
		++res;
	} while(res < 6 && next_permutation(a, a + n));

	if(res < 6) {
		cout << "No";
		return 0;
	}

	cout << "Yes" << endl;

  return 0;
}
