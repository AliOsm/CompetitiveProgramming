#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, x, res = 0;
  scanf("%lld %lld", &n, &x);
  
  for(int i = 1, tmp; i <= n; ++i) {
    if(x % i == 0) {
      tmp = x / i;
      if(tmp <= n)
        ++res;
    }
  }
  
  printf("%lld\n", res);
  
  return 0;
}
