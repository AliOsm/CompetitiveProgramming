#include <bits/stdc++.h>

using namespace std;

int main() {
	int kase = 1, n0;
	while(cin >> n0 && n0 != 0) {
		int n1 = 3 * n0;

		int n2;
		if(n1 % 2 == 0)
			n2 = n1 / 2;
		else
			n2 = (n1 + 1) / 2;

		int n3 = 3 * n2;

		int n4 = n3 / 9;

		printf("%d. %s %d\n", kase++, n1 % 2 == 0 ? "even" : "odd", n4);
	}

	return 0;
}

