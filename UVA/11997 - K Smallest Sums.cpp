/*
  Idea:
    - If we solve the problem for two array a and b, then we can solve it for the k arrays.
    - Each time insert in priority_queue insert the summations a[0]+b[0], a[1]+b[0], a[2]+b[0], ..., a[n]+b[0].
    - a[0]+b[0] is the smallest sum, so it is fixed.
    - Each time pop the smallest element from the priority_queue and insert its value minus the value of the b
      element in this value plus the value of the next element in the array b.
    - Do the previous algorithm for two arrays at a time.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 751;
int k, a[2][N];
priority_queue<pair<int, int> > pq;

int main() {
  while(scanf("%d", &k) != EOF) {
    for(int i = 0; i < k; ++i)
      scanf("%d", &a[0][i]);
    sort(a[0], a[0] + k);

    for(int i = 1; i < k; ++i) {
      for(int j = 0; j < k; ++j)
        scanf("%d", &a[1][j]);
      sort(a[1], a[1] + k);

      while(!pq.empty())
        pq.pop();

      for(int j = 0; j < k; ++j)
        pq.push(make_pair(-(a[0][j] + a[1][0]), 0));
      
      for(int j = 0; j < k; ++j) {
        pair<int, int> p = pq.top();
        pq.pop();
        a[0][j] = -p.first;
        pq.push(make_pair(-(a[0][j] - a[1][p.second] + a[1][p.second + 1]), p.second + 1));
      }
    }

    for(int i = 0; i < k; ++i)
      printf("%s%d", i == 0 ? "" : " ", a[0][i]);
    puts("");
  }

  return 0;
}
