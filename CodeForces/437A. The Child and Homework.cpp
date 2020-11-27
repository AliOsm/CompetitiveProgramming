#include <bits/stdc++.h>

using namespace std;

bool g[4];
int a[4];
string tmp;

int main() {
  for(int i = 0; i < 4; ++i) {
    cin >> tmp;
    a[i] = tmp.length() - 2;
  }

  int all = 0;
  for(int i = 0; i < 4; ++i) {
    int cnt1 = 0, cnt2 = 0;
    for(int j = 0; j < 4; ++j) {
      if(i == j)
        continue;
      if(a[i] <= a[j] / 2)
        cnt1 += 1;
      if(a[i] >= a[j] * 2)
        cnt2 += 1;
    }
    if(cnt1 == 3 || cnt2 == 3)
      g[i] = true, all += 1;
  }

  if(all != 1) {
    puts("C");
    return 0;
  }

  for(int i = 0; i < 4; ++i) {
    if(g[i]) {
      printf("%c", 'A' + i);
      return 0;
    }
  }

  return 0;
}
