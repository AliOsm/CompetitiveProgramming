#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, f[10];
char s[N];

int main() {
  scanf("%d\n%s", &n, s);
  for(int i = 1; i <= 9; ++i)
    scanf("%d", f + i);

  bool conv = false;
  for(int i = 0; s[i] != '\0'; ++i) {
    if((conv && f[s[i] - '0'] >= s[i] - '0') || (!conv && f[s[i] - '0'] > s[i] - '0'))
      conv = true;
    if(conv && f[s[i] - '0'] < s[i] - '0')
      break;
    if(conv)
      s[i] = f[s[i] - '0'] + '0';
  }

  puts(s);

  return 0;
}
