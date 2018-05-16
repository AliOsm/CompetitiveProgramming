#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
bool vis[1001];
vector<int> sol;

int main() {
  int n, a[51] = {0};
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  for(int i = n - 1; i >= 0; --i)
    if(vis[a[i]] == false) {
      sol.push_back(a[i]);
      vis[a[i]] = true;
    }

  cout << sol.size() << endl;
  for(int i = sol.size() - 1; i >= 0; --i)
    cout << sol[i] << ' ';
  cout << endl;

  return 0;
}
