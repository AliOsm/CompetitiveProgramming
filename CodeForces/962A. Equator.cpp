#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[200001] = {0}, tot1 = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		tot1 += a[i];
	}
    
  if(tot1 % 2 == 1)
    ++tot1;

	int i = 0, tot = 0;
	while(i < n && tot < tot1 / 2) {
		tot += a[i];
		++i;
	}

	cout << i << endl;

  return 0;
}
