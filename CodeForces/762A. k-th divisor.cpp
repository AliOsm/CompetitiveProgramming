#include <bits/stdc++.h>

using namespace std;

vector<long long> d;
long long n, k;

int main() {
  scanf("%lld %lld", &n, &k);
  
  for(int i = 1; 1ll * i * i <= n; ++i) {
    if(n % i == 0) {
      d.push_back(i);
      
      if(n / i != i)
        d.push_back(n / i);
    }
  }
  
  sort(d.begin(), d.end());
  
  if(d.size() < k) {
    puts("-1");
    return 0;
  }
  
  printf("%lld\n", d[k - 1]);
  
  return 0;
}

