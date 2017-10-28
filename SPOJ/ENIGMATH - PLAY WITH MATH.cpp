#include <bits/stdc++.h>

using namespace std;

int t, n, m;
long long res;

long long lcm(int a, int b) {
  return (1ll * a * b) / __gcd(a, b);
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d", &n, &m);
    res = lcm(n, m);
    printf("%d %d\n", res / n, res / m);
  }
  
  return 0;
}
