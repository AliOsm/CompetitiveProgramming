#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 1;
int n, s;
long long a[N];

int main() {
  scanf("%d %d", &n, &s);
  a[0] = 1;
  for(int i = 1; i <= n; ++i)
    scanf("%lld", a + i);

  int end = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] * a[i - 1] > s)
      break;
    end = i;
    a[i] = a[i - 1] * a[i];
  }

  int res = 0;
  for(int i = end; i >= 0; --i) {
    res += s / a[i];
    s %= a[i];
  }

  printf("%d\n", res);

  return 0;
}
