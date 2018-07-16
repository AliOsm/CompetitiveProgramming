#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n, m, a[N], b[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < m; ++i)
    scanf("%d", b + i);
  
  for(int i = 1; i < N; ++i) {
    bool ok = true, en = false;;

    for(int j = 0; j < n; ++j) {
      if(a[j] > i) {
        ok = false;
        break;
      }

      if(a[j] * 2 <= i)
        en = true;
    }

    if(!ok || !en)
      continue;
    
    ok = true;
    for(int j = 0; j < m; ++j)
      if(b[j] <= i) {
        ok = false;
        break;
      }
    
    if(!ok)
      continue;
    
    printf("%d\n", i);
    return 0;
  }

  puts("-1");

  return 0;
}
