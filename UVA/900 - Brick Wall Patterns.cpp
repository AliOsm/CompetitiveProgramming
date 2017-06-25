#include <iostream>
#include <memory.h>

using namespace std;

long long fib[55];

long long  rec(int i) {
	long long &ret = fib[i];
	if(ret != -1) return ret;
	return ret = rec(i - 1) + rec(i - 2);
}

int main() {
	memset(fib, -1, sizeof fib);
	fib[0] = 0;
	fib[1] = 1;
	rec(54);

	int n;
	while(cin >> n && n != 0)
		cout << fib[n + 1] << endl;

	return 0;
}

