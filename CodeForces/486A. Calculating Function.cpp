#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
  scanf("%lld", &n);
  
  if(n & 1)
    printf("%lld\n", (n - 1) / 2 - n);
  else
    printf("%lld\n", n / 2);
  
  return 0;
}

