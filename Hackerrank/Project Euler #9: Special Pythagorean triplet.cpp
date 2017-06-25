#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;

map<int, int> mp;

int main() {
	int c_sqr, c_sqrt, sum, prod;
	for(int a = 1; a < 3001; ++a)
		for(int b = 1; b < 3001; ++b) {
			c_sqr = (a * a) + (b * b);
			c_sqrt = sqrt(c_sqr);
			if(c_sqr == c_sqrt * c_sqrt) {
				sum = a + b + c_sqrt;
				prod = a * b * c_sqrt;
				if(!mp.count(sum) || (mp.count(sum) && mp[sum] < prod))
					mp[sum] = prod;
			}
		}

	int t, n;
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d", &n);

		if(mp.count(n))
			printf("%d\n", mp[n]);
		else
			puts("-1");
	}

    return 0;
}

