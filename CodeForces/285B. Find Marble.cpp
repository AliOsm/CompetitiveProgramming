#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int n, s, t, a[N];

int main() {
  scanf("%d %d %d", &n, &s, &t);
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  
  for(int i = 0; i <= 1000000; ++i) {
    if(s == t) {
      printf("%d\n", i);
      return 0;
    }
    
    s = a[s];
  }
  
  puts("-1");
  
  return 0;
}
