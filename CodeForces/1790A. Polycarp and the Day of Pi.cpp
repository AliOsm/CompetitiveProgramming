#include <bits/stdc++.h>

using namespace std;

int t;
const string PI = "314159265358979323846264338327";
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

  scanf("%d", &t);

  while(t-- != 0) {
    cin >> s;

    int c = 0;
    for(int i = 0; i < s.length() && s[i] == PI[i]; ++i) {
      ++c;
    }

    printf("%d\n", c);
  }

	return 0;
}
