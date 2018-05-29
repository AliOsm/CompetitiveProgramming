#include <bits/stdc++.h>

using namespace std;

int n, m, pos, clk;

int main() {
  cin >> n >> m;
  for(int i = 0, t, a; i < m; ++i) {
  	cin >> t >> a;

  	if(t == 1)
  		pos = (a + pos) % n;
  	else
  		pos = (n + a - pos) % n, clk = !clk;
  }

  if(!clk)
  	cout << 1 << ' ' << n - pos << endl;
  else
  	cout << 2 << ' ' << pos << endl;

  return 0;
}
