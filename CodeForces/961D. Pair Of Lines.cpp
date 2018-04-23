#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], b[N];
bool vis[N];

bool solve(int i1, int i2) {
	memset(vis, false, sizeof vis);

	long long s1, s2;
  int v1 = -1, v2 = -1;

  s1 = b[i2] - b[i1];
  s2 = a[i2] - a[i1];

  vis[i1] = vis[i2] = true;
  int cnt = 2;
  for(int i = 0; i < n; ++i) {
  	if(vis[i])
  		continue;

  	long long ss1, ss2;
  	ss1 = b[i] - b[i1];
  	ss2 = a[i] - a[i1];

  	if(s2 * ss1 == s1 * ss2) {
  		vis[i] = true;
  		++cnt;
  	} else {
  		if(v1 == -1)
  			v1 = i;
  		else if(v2 == -1)
  			v2 = i;
  	}
  }

  if(n - cnt <= 2) {
  	return true;
  }

  long long e1, e2;

  e1 = b[v2] - b[v1];
  e2 = a[v2] - a[v1];
  vis[v1] = vis[v2] = true;
  cnt += 2;

  for(int i = 0; i < n; ++i) {
  	if(vis[i])
  		continue;

  	long long ss1, ss2;
  	ss1 = b[i] - b[v1];
  	ss2 = a[i] - a[v1];

  	if(e2 * ss1 == e1 * ss2) {
  		vis[i] = true;
  		++cnt;
  	}
  }

  if(cnt == n) {
  	return true;
  }

  return false;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> a[i] >> b[i];

  if(n <= 2) {
  	cout << "YES" << endl;
  	return 0;
  }

  if(solve(0, 1) || solve(0, 2) || solve(1, 2))
  	cout << "YES" << endl;
  else
  	cout << "NO" << endl;

  return 0;
}
