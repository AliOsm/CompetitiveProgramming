#include <bits/stdc++.h>
 
using namespace std;
 
int const MOD = 1e9 + 7;
int t, a, b, c, n, med;
unsigned long long sum;
 
int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d %d %d", &a, &b, &c, &n);
 
    priority_queue<long long> l, r;
    
    l.push(1);
    sum = 1;
 
    for(int i = 2, nxt; i <= n; ++i) {
      nxt = (1ll * a * l.top() + 1ll * b * i + c) % MOD;
      sum += nxt;
 
      if(l.top() < nxt)
        r.push(-nxt);
      else
        l.push(nxt);
      
      while(l.size() > r.size() + 1)
        r.push(-l.top()), l.pop();
      
      while(r.size() > l.size())
        l.push(-r.top()), r.pop();
    }
 
    printf("%llu\n", sum);
  }
 
  return 0;
}
