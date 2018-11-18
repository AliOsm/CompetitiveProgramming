#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int n, a[N], x[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i);

  vector<int> sol;
  for(int i = 1; i <= n; ++i) {
    x[i - 1] = a[i] - a[i - 1];
    bool ok = true;
    for(int j = 1, cnt = 0; j <= n; ++j, ++cnt) {
      if(x[cnt % i] + a[j - 1] != a[j]) {
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

  return 0;
}
