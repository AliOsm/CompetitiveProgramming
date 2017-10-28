#include <bits/stdc++.h>

using namespace std;

int const N = 1000001;
int t, a, b, gcd;
vector<int> all;

void divisors(int n) {
  int sqrtn = sqrt(n);
  for(int i = 1; i <= sqrtn; ++i) {
    if(n % i == 0) {
      ++all[n];
      if(n / i != i)
        ++all[n];
    }
  }
}

int main() {
  all.resize(N);
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d", &a, &b);
    gcd = __gcd(a, b);
    if(all[gcd] == 0)
      divisors(gcd);
    printf("%d\n", all[gcd]);
  }
  
  return 0;
}
