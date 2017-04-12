#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  if(n == m) {
    printf("%d\n", n + 1);
    for(int i = 0, j = m; j >= 0; i++, j--)
      printf("%d %d\n", i, j);
  } else if(n > m) {
    printf("%d\n", min(n, m + 1));
    for(int i = 0, j = m; j >= 0; i++, j--)
      printf("%d %d\n", i, j);
  } else if(n < m) {
    printf("%d\n", min(n + 1, m));
    for(int i = 0, j = m; i <= n; i++, j--)
      printf("%d %d\n", i, j);
  }
  
  return 0;
}

