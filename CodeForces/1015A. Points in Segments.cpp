/*
  Idea:
    - Implementation.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, m, a[N], b[N];
vector<int> sol;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", a + i, b + i);

  for(int i = 1; i <= m; ++i) {
    bool ok = true;
    for(int j = 0; j < n; ++j) {
      if(i >= a[j] && i <= b[j]) {
        ok = false;
        break;
      }
    }
    if(ok)
      sol.push_back(i);
  }

  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%d ", sol[i]);
  puts("");

  return 0;
}
