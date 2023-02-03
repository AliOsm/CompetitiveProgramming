#include <bits/stdc++.h>

using namespace std;

int t, n, s, r;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

  scanf("%d", &t);

  while(t-- != 0) {
    scanf("%d %d %d", &n, &s, &r);

    vector<int> dices;
    dices.resize(n);
    dices[0] = s - r;
  
    while(r > 0) {
      for(int i = 1; r > 0 && i < dices.size(); ++i) {
        ++dices[i];
        --r;
      }
    }
  
    for(int i = 0; i < dices.size(); ++i) {
      printf("%d ", dices[i]);
    }
    puts("");
  }

	return 0;
}
