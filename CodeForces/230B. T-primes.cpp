#include <iostream>
#include <cmath>

using namespace std;

int const N = 1e6 + 1;
bool prime[N];

void sieve() {
  prime[0] = prime[1] = true;
  
  for(int i = 4; i <= N; i++)
    prime[i] = i % 2 == 0;
  
  for(int i = 3; i * i <= N; i += 2)
    if(!prime[i])
      for(int j = i * i; j <= N; j += i + i)
        prime[j] = true;
}

int main() {
  sieve();
  
  int n;
  cin >> n;
  
  long long xi, tmp;
  while(n--) {
    cin >> xi;
    tmp = sqrt(xi);
    if(tmp * tmp == xi && !prime[tmp])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  
  return 0;
}

