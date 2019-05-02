#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, b, a, mxa, arr[N];

int main() {
  scanf("%d %d %d", &n, &b, &a);
  mxa = a;
  for(int i = 0; i < n; ++i)
    scanf("%d", arr + i);
  
  int i = 0;
  for(; i < n; ++i) {
    if(arr[i] == 1 && a < mxa && b > 0) {
      ++a, --b;
    } else if(a > 0) {
      --a;
    } else if(b > 0) {
      --b;
    } else {
      break;
    }
  }

  printf("%d\n", i);

  return 0;
}
