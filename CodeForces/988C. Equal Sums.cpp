/*
  Idea:
    - Greedy.
    - For each new sequence of numbers try to find any other sequence before
      it, have the same summation if you remove each element in it.
    - We can do this using a set of struct.
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
	int idx, sum, rem;

	node() {}

	node(int idx, int sum, int rem) :
		idx(idx), sum(sum), rem(rem) {}

	bool operator<(const node &n) const {
		if(sum != n.sum)
			return sum < n.sum;
		return idx < n.idx;
	}
};

int const N = 2e5 + 1;
int k, n, to[N];
vector<vector<int> > g;
set<node> st;
set<node>::iterator it;

int main() {
  scanf("%d", &k);
  g.resize(k);
  for(int i = 0; i < k; ++i) {
  	scanf("%d", &n);
  	g[i].resize(n);
  	for(int j = 0; j < n; ++j) {
  		scanf("%d", &g[i][j]);
  		to[i] += g[i][j];
  	}

  	for(int j = 0; j < n; ++j) {
  		it = st.lower_bound(node(-1e9, to[i] - g[i][j], -1e9));
  		if(it != st.end() && it->sum == to[i] - g[i][j]) {
  			puts("YES");
  			printf("%d %d\n", it->idx + 1, it->rem + 1);
  			printf("%d %d\n", i + 1, j + 1);
  			return 0;
  		}
  	}

  	for(int j = 0; j < n; ++j)
  		st.insert(node(i, to[i] - g[i][j], j));
  }

  puts("NO");

  return 0;
}
