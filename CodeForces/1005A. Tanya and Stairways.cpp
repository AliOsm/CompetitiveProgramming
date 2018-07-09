#include <bits/stdc++.h>

using namespace std;

int n, a[1001];
vector<int> sol;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  for(int i = 0, cnt; i < n - 1; ++i) {
    cnt = 0;
    while(i < n - 1 && a[i] < a[i + 1])
      ++cnt, ++i;
    sol.push_back(cnt + 1);
  }
  if(a[n - 1] == 1)
    sol.push_back(1);

  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%s%d", i == 0 ? "" : " ", sol[i]);
  puts("");

  return 0;
}
