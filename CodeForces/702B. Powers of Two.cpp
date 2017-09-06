#include <bits/stdc++.h>

using namespace std;

int const N = 35;
long long power[N], n;
map<int, int> mp;

int main() {
  power[0] = 1;
  for(int i = 1; i < N; ++i)
    power[i] = power[i - 1] * 2;
  
  scanf("%d", &n);
  for(int  i = 0, tmp; i < n; ++i) {
    scanf("%d", &tmp);
    ++mp[tmp];
  }
  
  long long res = 0;
  for(map<int, int>::iterator it = mp.begin(); it != mp.end();) {
    for(int i = 0; i < N; ++i) {
      long long d = abs(it->first - power[i]);
      map<int, int>::iterator tmp = mp.find(d);
      
      if(tmp != mp.end() && tmp != it)  
        res += 1ll * it->second * tmp->second;
      
      if(it->first + it->first == power[i])
        res += (1ll * it->second * (it->second - 1)) / 2;
    }
    
    mp.erase(it);
    it = mp.begin();
  }
  
  printf("%lld\n", res);
  
  return 0;
}
