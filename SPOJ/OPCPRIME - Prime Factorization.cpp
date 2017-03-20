#include <stdio.h>
#include <vector>
#include <bitset>
 
using namespace std;

long long const N = 1e6 + 1000;
bitset<N> bs;
vector<int> p;

void sieve() {
  bs[0] = bs[1] = 1;
  
  for (int i = 2; i * i < N; i++)
    if (bs[i] == 0)
      for (int j = i * i; j < N; j += i)
        bs[j] = 1;
 
  for (int i = 0; i < N; i++)
    if (bs[i] == 0)
      p.push_back(i);
}
 
void primeFact(long long n) {
  int freq;
  for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
    freq = 0;
 
    while (n % p[i] == 0) {
      freq++;
      n /= p[i];
    }
 
    if (freq != 0)
      printf("%d\n", p[i]);
  }
 
  if (n != 1)
    printf("%lld\n", n);
}
 
int main() {
  long long x;
  
  sieve();
  
  while(scanf("%lld", &x) == 1)
    primeFact(x);
    
  return 0;
}

