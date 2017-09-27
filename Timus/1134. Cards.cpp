#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int const N = 1e4 + 1;
int n, m, a[N], fr[N];

int main() {
  scanf("%d %d", &n, &m);
  if(m > n) {
    puts("NO");
    return 0;
  }
  for(int i = 0; i < m; ++i)
    scanf("%d", a + i);
  sort(a, a + m);
  
  fr[0] = fr[n] = 1;
  for(int i = 1; i <= n - 1; ++i)
    fr[i] = 2;
  
  for(int i = 0; i < m; ++i) {
    if(a[i] == 0) {
      if(fr[0] <= 0 || fr[1] <= 0) {
        puts("NO");
        return 0;
      } else {
        --fr[0], --fr[1];
        continue;
      }
    }
    
    if(a[i] == n) {
      if(fr[n] <= 0 || fr[n - 1] <= 0) {
        puts("NO");
        return 0;
      } else {
        --fr[n], --fr[n - 1];
        continue;
      }
    }
    
    if(fr[a[i]] > 0 && (fr[a[i] + 1] > 0 || fr[a[i] - 1] > 0)) {
      --fr[a[i]];
      if(fr[a[i] - 1] > 0)
        --fr[a[i] - 1];
      else if(fr[a[i] + 1] > 0)
        --fr[a[i] + 1];
    } else {
      puts("NO");
      return 0;
    }
  }
  
  puts("YES");

  return 0;
}
