#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> strs;

int shift(string s1, string s2) {
  char tmp;
  int res = 0;

  while(s1 != s2) {
    tmp = s1.back();
    s1.pop_back();
    s1 = tmp + s1;
    res++;

    if(res > 100)
	return 1e7;
  }
  return res;
}

int main() {
  cin >> n;
  
  strs.resize(n);
  for(int i = 0; i < n; i++)
    cin >> strs[i];

  int res = 1e9;
  for(int i = 0; i < n; i++) {
    int r = 0;
    
    for(int j = 0; j < strs.size(); j++) {
      if(j == i) continue;
      r += shift(strs[i], strs[j]);
    }
    
    res = min(res, r);
  }
  
  if(res >= 1e7) cout << -1 << endl;
  else cout << res << endl;
  
  return 0;
}
