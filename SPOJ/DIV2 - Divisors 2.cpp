#include <bits/stdc++.h>
 
using namespace std;
 
int const N = 1000001;
int divisors[N];
bool sol[N];
vector<int> res;
 
int main() {
  for(int i = 1; i < N; ++i)
    for(int j = i; j < N; j += i)
      ++divisors[j];
  
  memset(sol, true, sizeof sol);
  for(int i = 1; i < N; ++i)
    for(int j = i; j < N; j += i)
      if(divisors[j] <= 3 || divisors[j] % divisors[i] != 0)
        sol[j] = false;
  
  for(int i = 1; i < N; ++i)
    if(sol[i])
      res.push_back(i);
  
  for(int i = 107; i < (int)res.size(); i += 108)
    printf("%d\n", res[i]);
  
  return 0;
} 
