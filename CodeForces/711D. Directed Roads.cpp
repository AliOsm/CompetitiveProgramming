#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1, M = 1e9 + 7;
int n, low[N], idx[N], comp[N], sol[N], dfs, id;
bool in[N];
vector<int> st;
vector<vector<int> > g;

void DFS(int v) {
  low[v] = idx[v] = dfs++;
  in[v] = true;
  st.push_back(v);

  for(int i = 0; i < g[v].size(); i++)
    if(idx[g[v][i]] == -1) {
      DFS(g[v][i]);
      low[v] = min(low[v], low[g[v][i]]);
    } else if(in[g[v][i]])
      low[v] = min(low[v], low[g[v][i]]);

  if(low[v] == idx[v]) {
    int node;
    do {
      node = st.back();
      in[node] = false;
      st.pop_back();
      ++comp[id];
    } while(node != v);

    id++;
  }
}

int fst(int base, int power) {
	int ret = 1;

	while(power > 0) {
		if(power % 2 == 0) {
			power /= 2;
			base = 1ll * base * base % M;
		} else {
			--power;
			ret = 1ll * ret * base % M;

			power /= 2;
			base = 1ll * base * base % M;
		}
	}

	return ret;
}

int main() {
  cin >> n;
  g.resize(n);
  for(int i = 0; i < n; ++i) {
  	int tmp;
  	cin >> tmp;
  	g[i].push_back(--tmp);
  }

  memset(idx, -1, sizeof idx);
  for(int i = 0; i < n; ++i)
  	if(idx[i] == -1)
  		DFS(i);

 	for(int i = 0; i < id; ++i)
 		sol[i] = (fst(2, comp[i]) - (comp[i] == 1 ? 0 : 2) + M) % M;

	long long res = 1;
	for(int i = 0; i < id; ++i)
		res = res * sol[i] % M;

 	cout << res << endl;

  return 0;
}
