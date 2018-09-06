/*
  Idea:
    - Brute force.
    - Start from each student and try to find the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, p[N];
bool vis[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", p + i), --p[i];

  for(int i = 0; i < n; ++i) {
    memset(vis, false, sizeof vis);

    vis[i] = true;
    int cur = p[i];
    while(!vis[cur]) {
      vis[cur] = true;
      cur = p[cur];
    }

    printf("%d ", cur + 1);
  }
  puts("");

  return 0;
}
