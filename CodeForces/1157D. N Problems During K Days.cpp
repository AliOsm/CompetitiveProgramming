#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, k, a[N];

int main() {
  scanf("%d %d", &n, &k);

  if(n < 1ll * k * (k + 1) / 2) {
    puts("NO");
    return 0;
  }

  for(int i = 0; i < k; ++i)
    a[i] = i + 1, n -= (i + 1);
  
  int add = n / k;
  int rem = n % k;

  for(int i = 0; i < k; ++i)
    a[i] += add;
  
  for(int i = k - 1; i > 0; --i) {
    if(rem == 0)
      break;
    
    add = min(a[i - 1] * 2 - a[i], rem);
    rem -= add;
    a[i] += add;
  }

  if(rem > 0) {
    puts("NO");
    return 0;
  }

  puts("YES");
  for(int i = 0; i < k; ++i)
    printf("%s%d", i == 0 ? "" : " ", a[i]);
  puts("");

  return 0;
}
