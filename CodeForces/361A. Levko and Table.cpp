#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i, puts(""))
    for(int j = 0; j < n; ++j)
      if(i == j)
        printf("%d ", k);
      else
        printf("0 ");

  return 0;
}
