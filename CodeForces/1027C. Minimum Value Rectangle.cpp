/*
  Idea:
    - If there is 4 inctances (or more) from the same length
      then we will use this length, because it give us the minimum
      value for the equation.
    - Otherwise, sort the other lengths that appears more than one
      time and check each adjacent lengths and minimize.
*/

#include <bits/stdc++.h>

using namespace std;

int T, n;
map<int, int> mp;
vector<pair<int, int> > all;

double check(int l1, int l2) {
  return pow(l1 * 2 + l2 * 2, 2) / (1.0 * l1 * l2);
}

int main() {
  scanf("%d", &T);
  while(T-- != 0) {
    mp.clear();
    scanf("%d", &n);
    for(int i = 0, tmp; i < n; ++i) {
      scanf("%d", &tmp);
      ++mp[tmp];
    }

    all.clear();
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
      if(it->second > 1)
        all.push_back(make_pair(it->first, it->second));

    int l1 = -1, l2 = -1;
    for(int i = 0; i < all.size(); ++i)
      if(all[i].second > 3)
        l1 = l2 = all[i].first;

    if(l1 == -1 && l2 == -1) {
      double mn = 1e9, tmp;
      for(int i = 1; i < all.size(); ++i) {
        tmp = check(all[i].first, all[i - 1].first);
        if(mn - 1e-15 > tmp) {
          mn = tmp;
          l1 = all[i].first;
          l2 = all[i - 1].first;
        }
      }
    }

    printf("%d %d %d %d\n", l1, l1, l2, l2);
  }

  return 0;
}
