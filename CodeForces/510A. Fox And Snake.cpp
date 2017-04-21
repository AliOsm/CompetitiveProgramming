#include <stdio.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  bool where = true;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(i % 2 == 1) putchar('#');
      else {
        if(where && j == m) { putchar('#'); }
        else if(!where && j == 1) { putchar('#'); }
        else putchar('.');
      }
    }
    if(i % 2 == 0) where = !where;
    putchar('\n');
  }

  return 0;
}

