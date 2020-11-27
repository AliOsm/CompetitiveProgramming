#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  scanf("%d", &n);

  if(n == 0) {
    puts("O-|-OOOO");
    return 0;
  }
  
  while(n != 0) {
    int cur = n % 10;
    n /= 10;

    if(cur >= 5) {
      printf("-O|");
      cur -= 5;
    } else {
      printf("O-|");
    }

    for(int i = 0; i < cur; ++i)
      printf("O");
    printf("-");
    for(int i = 0; i < 4 - cur; ++i)
      printf("O");
    puts("");
  }

  return 0;
}
