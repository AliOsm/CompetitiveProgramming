#include <bits/stdc++.h>

using namespace std;

long long k, l;

int main() {
  scanf("%lld %lld", &k, &l);

  long long tmp = k;
  int res = 0;
  while(k <= l) {
    if(k == l) {
      puts("YES");
      printf("%d\n", res);
      return 0;
    }
    k *= tmp;
    ++res;
  }

  puts("NO");

  return 0;
}
