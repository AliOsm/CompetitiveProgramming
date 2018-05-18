#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;

	while (t-- != 0) {
		int n, m;
		cin >> n >> m;
		
		if (n != m)
			cout << ((n+1)/2) * ((m+1)/2)<< endl;
		else {
			int tmp = (n+1)/2;
			cout << tmp * (tmp+1) / 2 << endl;
		}
	}

	return 0;
}
