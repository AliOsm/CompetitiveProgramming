#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int const N = 1e8 + 1;
bool prime[N];
vector<int> primes;

void sieve() {
  prime[0] = prime[1] = true;
  
  for(int i = 4; i <= N; i++)
    prime[i] = i % 2 == 0;
  
  for(int i = 3; i * i <= N; i += 2)
    if(!prime[i])
      for(int j = i * i; j <= N; j += i + i)
        prime[j] = true;
  
  for(int i = 2; i <= N; i++)
    if(!prime[i])
      primes.push_back(i);
}

int main() {
  sieve();
  
  int n;
  double indx;
  while(cin >> n && n) {
    indx = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    cout << fixed << setprecision(1) << abs(indx - (n/log(n))) / indx * 100 << endl;
  }
  
  return 0;
}

