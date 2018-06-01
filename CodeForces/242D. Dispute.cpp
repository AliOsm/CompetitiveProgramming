/*
  Idea:
    - Greedy.
    - If there is no zeros in the array `a` then print 0.
    - If there is zeros in the array `a` push them in a queue and start BFS
      from them, each time you pop a node from the queue check if the value
      of this node in `a` not equal to the value of it in the current array
      (`b`) then do not process it, otherwise add 1 to the value of this node
      and its neighbors, finally for each neighbor if the value of it in `a`
      equal the current value of it in `b` then push it in the queue.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, a[N], b[N];
bool vis[N];
vector<vector<int> > g;
vector<int> sol;
queue<int> q;

int main() {
  scanf("%d %d", &n, &m);
  g.resize(n);
  for(int i = 0, a, b; i < m; ++i) {
  	scanf("%d %d", &a, &b);
  	--a, --b;
  	g[a].push_back(b);
  	swap(a, b);
  	g[a].push_back(b);
  }
  for(int i = 0; i < n; ++i) {
  	scanf("%d", a + i);
  	if(a[i] == 0)
  		q.push(i);
  }

  if(q.empty()) {
  	puts("0");
  	return 0;
  }

  while(!q.empty()) {
  	int fr = q.front();
  	q.pop();

  	if(vis[fr] || b[fr] != a[fr])
  		continue;
  	vis[fr] = true;
  	sol.push_back(fr + 1);

  	++b[fr];
  	for(int i = 0; i < g[fr].size(); ++i)
  		if(++b[g[fr][i]] == a[g[fr][i]])
  			q.push(g[fr][i]);
  }

  for(int i = 0; i < n; ++i)
  	if(a[i] == b[i]) {
  		puts("-1");
  		return 0;
  	}

  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
  	printf("%s%d", i == 0 ? "" : " ", sol[i]);
  puts("");

  return 0;
}
