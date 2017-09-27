#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int const N = 1e4 + 1;
int n, k;
vector<int> adj[N];
bool vis[N];

int dfs(int u, int tr) {
  vis[u] = true;

  for(int i = 0; i < adj[u].size(); ++i){
    int v = adj[u][i];
    if(!vis[v] && v != k){
      if(dfs(v, !tr))
        if(tr)
	  return 1;
      else if(!tr)
	  return 0;
    }
  }
  if(!tr)
    return 1; 
  return 0;
}
int main() {
  cin >> n >> k;
  for(int i = 0;i < n-1; ++i){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);    
  }

  if(!dfs(k, true))
    cout << "First player loses\n";
  else {
    int yes = 10001;
    for(int i = 0; i < adj[k].size(); i++){
      memset(vis, 0, sizeof vis);
      int to = adj[k][i];
      if(dfs(to, 0))
	yes = min(yes, to);
    }    
    cout << "First player wins flying to airport " << yes << endl;    
  }

  return 0;
}
