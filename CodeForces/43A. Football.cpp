#include <bits/stdc++.h>
 
using namespace std;
 
char c[11];
int n;
string s;
vector<pair<int, string> > v;
map<string, int> m;
 
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%s", c);
    s = c;
    m[s] += 1;
  }
 
  for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    v.push_back(make_pair(it->second, it->first));
  sort(v.begin(), v.end());
 
  puts(v.back().second.c_str());
 
  return 0;
}
