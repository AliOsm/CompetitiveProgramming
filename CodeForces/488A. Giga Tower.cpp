#include <bits/stdc++.h>

using namespace std;

long long a, b;

bool check(long long b) {
  int e = 0;
  while(b != 0)
    e += (b % 10) == 8, b /= 10;
  return !(e > 0);
}

int main() {
  scanf("%lld", &a);
  b = a + 1;

  while(check(abs(b)))
    ++b;

  printf("%lld\n", b - a);

  return 0;
}
