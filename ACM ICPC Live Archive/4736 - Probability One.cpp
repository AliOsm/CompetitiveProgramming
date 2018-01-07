#include <bits/stdc++.h>

using namespace std;

int main() {
	int kase = 1, n0;
	while(cin >> n0 && n0 != 0)
		printf("%d. %s %d\n", kase++, n0 % 2 == 0 ? "even" : "odd", n0 / 2);

	return 0;
}

