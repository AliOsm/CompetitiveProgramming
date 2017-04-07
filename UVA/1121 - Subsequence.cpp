#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 1e5 + 1;
int n, arr[N], sum;

int main() {
	while(scanf("%d%d", &n, &sum) == 2) {
  	for (int i = 0; i < n; i++)
  	  scanf("%d", &arr[i]);

  	int l = 0, r = 0, res = 1e9;
  	long long cum = 0;
  	while (r < n) {
  	  cum += arr[r];

  	  while (cum >= sum) {
  	    res = min(res, r - l + 1);
  	    cum -= arr[l++];
  	  }

  	  ++r;
  	}

  	if(res != 1e9)
  	  printf("%d\n", res);
  	else
  	  puts("0");
	}

	return 0;
}
