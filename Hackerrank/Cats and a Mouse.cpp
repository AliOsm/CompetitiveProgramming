#include <stdio.h>
#include <cmath>

using namespace std;

typedef long long ll;

ll q, a[200001];

int main() {
	scanf("%lld", &q);

	int a, b, c;
	while(q-- != 0) {
		scanf("%d%d%d", &a, &b, &c);

		if(abs(a - c) == abs(b - c)) puts("Mouse C");
		else if(abs(a - c) < abs(b - c)) puts("Cat A");
		else puts("Cat B");
	}
}

