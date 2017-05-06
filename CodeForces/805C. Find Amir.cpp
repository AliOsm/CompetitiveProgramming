#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<bool> vis(n + 1, false);

	int from = 1, to = n, res = 0, tmp;
	vis[from] = true;
	while(!vis[to]) {
		vis[to] = true;
		res += (from + to) % (n + 1);
		tmp = from;
		from = to;
		if(tmp > to)
			to = tmp - 1;
		else
			to = tmp + 1;
	}

	printf("%d\n", res);

  return 0;
}

