#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, fr[N];

int main() {
  scanf("%d", &n);
  for(int i = 0, tmp; i < n; ++i) {
    scanf("%d", &tmp);
    ++fr[tmp];
  }

  for(int i = 0; i < N; ++i) {
    if(n % 2 == 0 && fr[i] > n / 2) {
      puts("NO");
      return 0;
    }

    if(n % 2 == 1 && fr[i] > n / 2 + 1) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");

  return 0;
}
