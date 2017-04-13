#include <stdio.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int cnt = n * m;

  int i = 1, j = 1;
  bool dir = true;
  while(k > 1) {
    printf("2");
    printf(" %d %d", i, j);
    dir ? j++ : j--;
    if(j > m) { j--; i++; dir = false; }
    if(j < 1) { j++; i++; dir = true; }
    printf(" %d %d", i, j);
    dir ? j++ : j--;
    if(j > m) { j--; i++; dir = false; }
    if(j < 1) { j++; i++; dir = true; }
    putchar('\n');
    k--;
    cnt -= 2;
  }

  printf("%d", cnt);
  while(i != n + 1 && j != m + 1) {
    printf(" %d %d", i, j);
    dir ? j++ : j--;
    if(j > m) { j--; i++; dir = false; }
    if(j < 1) { j++; i++; dir = true; }
  }
  putchar('\n');

  return 0;
}

