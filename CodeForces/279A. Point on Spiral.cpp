#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int x, y;

int main() {
  scanf("%d %d", &x, &y);

  int res = 0, cx = 0, cy = 0, d = 0, s = 1, c = 0;

  while(true) {
    if(c == 2) {
      ++s;
      c = 0;
    }

    for(int i = 0; i < s; ++i) {
      if(cx == x && cy == y) {
        printf("%d\n", res);
        return 0;
      }

      cx += dx[d];
      cy += dy[d];
    }

    if(cx == x && cy == y) {
      printf("%d\n", res);
      return 0;
    }

    ++res;
    ++d;
    d %= 4;
    ++c;
  }

  printf("%d\n", res);

  return 0;
}
