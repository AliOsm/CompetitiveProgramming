#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
char s[N], sol[N];

int main() {
  scanf("%s", s);
  int len = strlen(s);

  int cnt = 0;
  for(int i = 0; i < len; ++i)
    cnt += s[i] == '1';

  for(int i = 0, j = 0; i < len; ++i)
    if(s[i] != '1')
      sol[j++] = s[i];

  for(int i = 0; i < len; ++i)
    if(s[i] == '2')
      break;
    else if(s[i] != '1')
      putchar('0');

  for(int i = 0; i < cnt; ++i)
    putchar('1');

  bool ok = false;
  for(int i = 0; i < len; ++i) {
    if(s[i] == '2')
      ok = true;
    if(ok && s[i] != '1')
      putchar(s[i]);
  }

  puts("");

  return 0;
}
