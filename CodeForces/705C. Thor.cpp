/*
  idea:
    - We can implement the events in a smart way to avoid TLE verdict.
    - Track the number of notifications each application did and the total sum.
    - If event of type 2 occurs, then subtract the number of notifications this
      application did from the total sum, and remember that till this point the
      notifications of this application were read.
    - If event of type 3 occurs, then loop from the last position you was in
      to `t` and if the current event does not visited and the application
      notifications do not readed then subtract 1 from the total sum and the
      number of notifications of the current application.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;
int n, q, cnt[N], events[N], to[N], res[N];
bool vis[N];

int main() {
  scanf("%d %d", &n, &q);
  int type, x, sum = 0, lst = 1, tmp = 0, evecnt = 1;
  for(int i = 1; i <= q; ++i) {
    scanf("%d %d", &type, &x);

    if(type == 1) {
      ++sum;
      ++cnt[x];
      events[evecnt++] = x;
    } else if(type == 2) {
      sum -= cnt[x];
      cnt[x] = 0;
      to[x] = evecnt - 1;
    } else {
      for(; lst <= x; ++lst) {
        if(vis[lst])
          continue;
        if(to[events[lst]] >= lst) {
          vis[lst] = true;
          continue;
        }
        --sum;
        --cnt[events[lst]];
        vis[lst] = true;
      }
    }

    res[i] = sum;
  }

  for(int i = 1; i <= q; ++i)
    printf("%d\n", res[i]);

  return 0;
}
