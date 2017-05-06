#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
vector<long long> d;
 
int calc(long long i, long long j) {
  return (int)max(floor(log10(i)) + 1, floor(log10(j)) + 1);
}
 
int main() {
  long long n, tmp;
  cin >> n;
  
  tmp = sqrt(n);
  for(int i = 1; i <= tmp; i++)
    if(n % i == 0) {
      d.push_back(i);
      d.push_back(n / i);
    }
  
  sort(d.begin(), d.end());
  
  int res = 1e9;
  
  for(int i = 0, j = d.size() - 1; i <= j; i++, j--)
    res = min(res, calc(d[i], d[j]));
  
  cout << res << endl;
  
  return 0;
}
