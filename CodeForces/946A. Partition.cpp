#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, tmp, b = 0, c = 0;
  cin >> n;

  for(int i = 0; i < n; ++i) {
  	cin >> tmp;
  	if(tmp >= 0)
  		b += tmp;
  	else
  		c += tmp;
  }

  cout << b - c << endl;

  return 0;
}
