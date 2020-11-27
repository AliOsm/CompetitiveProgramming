#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  scanf("%d %d", &n, &k);

  if(n > 1 && k == 0) {
    puts("No solution");
    return 0;
  }
  
  printf("%d", k);
  if(n == 1)
    return 0;
  for(int i = 1; i < n; ++i)
    printf("0");
  puts("");

  return 0;
}
