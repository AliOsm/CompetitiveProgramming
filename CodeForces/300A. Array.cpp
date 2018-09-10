#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, a[N];
vector<int> sol[3];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  for(int i = 0; i < n; ++i)
    if(a[i] < 0)
      sol[0].push_back(a[i]);

  for(int i = 0; i < n; ++i)
    if(a[i] > 0)
      sol[1].push_back(a[i]);

  for(int i = 0; i < n; ++i)
    if(a[i] == 0)
      sol[2].push_back(a[i]);

  if(sol[1].size() == 0) {
    sol[1].push_back(sol[0].back());
    sol[0].pop_back();
    sol[1].push_back(sol[0].back());
    sol[0].pop_back();
  }

  if(sol[0].size() % 2 == 0) {
    sol[2].push_back(sol[0].back());
    sol[0].pop_back();    
  }

  printf("%d", int(sol[0].size()));
  for(int i = 0; i < sol[0].size(); ++i)
    printf(" %d", sol[0][i]);
  puts("");

  printf("%d", int(sol[1].size()));
  for(int i = 0; i < sol[1].size(); ++i)
    printf(" %d", sol[1][i]);
  puts("");

  printf("%d", int(sol[2].size()));
  for(int i = 0; i < sol[2].size(); ++i)
    printf(" %d", sol[2][i]);
  puts("");

  return 0;
}
