#include <bits/stdc++.h>

using namespace std;

char in[int(2e5 + 10)], out[int(2e5 + 10)];

int main() {
  scanf("%s", in + 5);
  int len = strlen(in + 5), cnt = 5;
  for(int i = 0; i < 5; ++i)
    out[i] = char(i + '0');
  for(int i = 5; i < len + 5; ++i) {
    if(out[cnt - 1] == in[i] && out[cnt - 2] == in[i])
      continue;
    if(out[cnt - 3] == out[cnt - 2] && out[cnt - 1] == in[i])
      continue;
    out[cnt++] = in[i];
  }
  out[cnt] = '\0';
  printf("%s\n", out + 5);
  
  return 0;
}
