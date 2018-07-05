#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, q, a[N], fr[35], fr1[35];

bool check() {
  for(int i = 0; i < 35; ++i)
    if(fr1[i] != 0)
      return false;
  return true;
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    bitset<32> bs(a[i]);
    for(int i = 0; i < 32; ++i)
      if(bs[i] == 1)
        ++fr[i];
  }

  while(q-- != 0) {
    int tmp;
    scanf("%d", &tmp);
    bitset<32> bs(tmp);

    memset(fr1, 0, sizeof fr1);
    for(int i = 0; i < 32; ++i)
      fr1[i] = bs[i];
    
    int cnt = 0;
    for(int i = 31; i >= 0; --i) {
      if(i > 0 && fr1[i] != 0 && fr[i] == 0) {
        fr1[i - 1] += fr1[i] * 2;
        fr1[i] = 0;
      } else if(i > 0 && fr1[i] != 0 && fr[i] < fr1[i]) {
        fr1[i - 1] += (fr1[i] - fr[i]) * 2;
        cnt += fr[i];
        fr1[i] = 0;
      } else if(fr1[i] != 0 && fr[i] >= fr1[i]) {
        cnt += fr1[i];
        fr1[i] = 0;
      }
    }

    if(check())
      printf("%d\n", cnt);
    else
      puts("-1");
  }

  return 0;
}
