#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, s;
long long a[N];

long long calc(int u, int v) {
  if(u > v)
    swap(u, v);
  return min(a[v - 1] - a[u - 1], a[u - 1] + a[n] - a[v - 1]);
}

int main() {
  scanf("%d %d", &n, &s);
  for(int i = 1; i <= n; ++i)
    scanf("%lld", a + i);
  
  for(int i = 1; i <= n; ++i)
    a[i] += a[i - 1];
  
  int a = s - 1, b = s + 1;
  if(a <= 0) a += n;
  if(b > n) b -= n;
  
  long long x, y, sol = 0;
  for(int i = 0; i < n; ++i) {
    x = calc(s, a);
    y = calc(s, b);
    
    if(x == y) {
      if(a < b) {
        s = a;
        --a;
      } else {
        s = b;
        ++b;
      }
      
      sol += x;
    } else if(x < y) {
      s = a;
      --a;
      sol += x;
    } else {
      s = b;
      ++b;
      sol += y;
    }
    
    if(a <= 0) a += n;
    if(b > n) b -= n;
  }
  
  printf("%lld\n", sol);
  
  return 0;
}
