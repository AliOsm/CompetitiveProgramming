/*
  Idea:
    - Greedy.
    - For each bottle keep taking from it until finish and go to the next one.
*/

#include <bits/stdc++.h>

using namespace std;

int n, w, m, fr[51];
vector<vector<pair<int, double> > > g;

int main() {
  scanf("%d %d %d", &n, &w, &m);
  int all = n * w;
  double one = 1.0 * all / m;

  g.resize(m);
  double cur, sum = 0;
  for(int i = 0, j = -1; j < n && i < m; ++i) {
    cur = 0;

    if(sum <= 1e-8)
      ++j, sum = w;
    if(j >= n)
      break;
    
    while(j < n && cur + 1e-8 < one) {
      if(sum == 0)
        ++j, sum = w;
      if(j >= n)
        break;
      
      if(one - cur + 1e-8 >= sum) {
        ++fr[j];
        if(fr[j] > 2) {
          puts("NO");
          return 0;
        }

        cur += sum;
        g[i].push_back({j + 1, sum});
        sum = 0;
      } else {
        ++fr[j];
        if(fr[j] > 2) {
          puts("NO");
          return 0;
        }

        double need = one - cur;
        cur += need, sum -= need;
        g[i].push_back({j + 1, need});
        break;
      }
    }

    if(cur + 1e-8 < one) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");
  for(int i = 0; i < m; ++i, puts(""))
    for(int j = 0; j < g[i].size(); ++j)
      printf("%s%d %.6lf", j == 0 ? "" : " ", g[i][j].first, g[i][j].second);

  return 0;
}
