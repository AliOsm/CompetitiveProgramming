/*
  Idea:
    - Using Dijkstra algorithm we can try to move from the node number 1
      to node number n using all other nodes, the state will be the current
      node and how many nodes I've reach before the current one.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 5e3 + 1;
int n, m, t, cost[N][N], parent[N][N];
bool vis[N][N];
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, pair<int, int> > > pq;
vector<int> sol;

int main() {
  scanf("%d %d %d", &n, &m, &t);
  g.resize(n);
  for(int i = 0, a, b, c; i < m; ++i) {
  	scanf("%d %d %d", &a, &b, &c);
  	--a, --b;
  	g[a].push_back({b, c});
  }

  memset(cost, 0x3f, sizeof cost);
  pq.push({0, {0, 0}});
  cost[0][0] = 0;

  while(!pq.empty()) {
  	int cst = -pq.top().first;
  	int cnt = -pq.top().second.first;
  	int cur = pq.top().second.second;
  	pq.pop();

  	if(vis[cur][cnt])
  		continue;
  	vis[cur][cnt] = true;

  	if(cur == n - 1)
  		continue;

  	for(int i = 0, nxt; i < g[cur].size(); ++i) {
  		nxt = g[cur][i].first;
  		int ncnt = cnt + 1;
  		int ncst = cst + g[cur][i].second;

  		if(vis[nxt][ncnt] || ncst > cost[nxt][ncnt] || ncst > t)
  			continue;

  		cost[nxt][ncnt] = ncst;
  		parent[nxt][ncnt] = cur;
  		pq.push({-ncst, {-ncnt, nxt}});
  	}
  }

  int res;
  for(int i = n; i >= 1; --i)
  	if(vis[n - 1][i]) {
  		res = i;
  		break;
  	}

  for(int i = n - 1; i != 0; i = parent[i][res--])
  	sol.push_back(i + 1);

  printf("%d\n", int(sol.size()) + 1);
  reverse(sol.begin(), sol.end());
  printf("1");
  for(int i = 0; i < sol.size(); ++i)
  	printf(" %d", sol[i]);
  puts("");

  return 0;
}
