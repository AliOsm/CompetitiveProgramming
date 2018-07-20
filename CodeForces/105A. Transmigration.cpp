#include <bits/stdc++.h>

using namespace std;

int n, m;
double k;
string s;
vector<pair<string, int> > sol;
map<string, int> mp1, mp2;
map<string, int>::iterator it1, it2;

int main() {
  scanf("%d %d %lf", &n, &m, &k);
  k += 1e-9;

  for(int i = 0; i < n; ++i) {
    cin >> s;
    double cur;
    scanf("%lf", &cur);
    mp1[s] = int(cur * k);
  }

  for(int i = 0; i < m; ++i) {
    cin >> s;
    mp2[s] = 0;
  }

  for(it1 = mp1.begin(); it1 != mp1.end(); ++it1) {
    if(it1->second < 100 && mp2.count(it1->first) == 1)
      sol.push_back({it1->first, 0});
    if(it1->second >= 100)
      sol.push_back({it1->first, it1->second});
  }

  for(it2 = mp2.begin(); it2 != mp2.end(); ++it2)
    if(mp1.count(it2->first) == 0)
      sol.push_back({it2->first, 0});

  sort(sol.begin(), sol.end());
  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%s %d\n", sol[i].first.c_str(), sol[i].second);

  return 0;
}
