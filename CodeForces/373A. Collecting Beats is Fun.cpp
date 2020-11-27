#include <bits/stdc++.h>

using namespace std;

int k, fr[10];

int main() {
  scanf("%d", &k);
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j) {
      char c;
      scanf(" %c", &c);
      if(c != '.')
        ++fr[c - '0'];
    }

  for(int i = 0; i < 10; ++i) {
    if(k * 2 < fr[i]) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");

  return 0;
}
