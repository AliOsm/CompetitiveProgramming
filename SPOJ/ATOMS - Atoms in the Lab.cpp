#include <bits/stdc++.h>
 
using namespace std;
 
int t, res;
long long n, k, m, tmp;
 
int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%lld %lld %lld", &n, &k, &m);
    
    if(n > m) {
      puts("0");
      continue;
    }
    
    res = 0;
    while(m >= n) {
      m /= k;
      ++res;
    }
    printf("%d\n", res - 1);
  }
  
  return 0;
} 
