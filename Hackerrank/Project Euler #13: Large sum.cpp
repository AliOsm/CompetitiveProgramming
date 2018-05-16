#include <bits/stdc++.h>

using namespace std;

int t;
char s[1001][60], sol[60];

int main() {
  scanf("%d", &t);
  for(int i = 0; i < t; ++i)
    scanf("%s", s[i]);

  int carry = 0;
  for(int i = 49; i >= 0; --i) {
    for(int j = 0; j < t; ++j)
      carry += (s[j][i] - '0');

    sol[i] = char(carry % 10 + '0');
    carry /= 10;
  }

  if(carry == 0) {
    for(int i = 0; i < 10; ++i)
      printf("%c", sol[i]);
    puts("");
  } else {
    int digits = log10(carry) + 1;
    printf("%d", carry);
    ++digits;
    for(int i = 0; digits <= 10; ++i, ++digits)
      printf("%c", sol[i]);
    puts("");
  }

  return 0;
}
