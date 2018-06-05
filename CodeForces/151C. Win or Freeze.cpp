/*
  Idea:
    - Do prime factorization on `q`.
    - If there is only 1 prime factor, then the number itself is a prime
      number and print 1\n0.
    - If there is two prime factors only the the second player will win.
    - If there is more than two prime factors, print the multiple of any
      of them.
*/

#include <bits/stdc++.h>

using namespace std;

long long q, sqrtq;
vector<int> fact;

int main() {
  scanf("%lld", &q);

  sqrtq = sqrt(q) + 1;

  for(int i = 2; i <= sqrtq; ++i)
  	while(q % i == 0)
  		fact.push_back(i), q /= i;
  if(q > 1)
  	fact.push_back(q);

  if(fact.size() <= 1)
  	puts("1\n0");
  else if(fact.size() == 2)
  	puts("2");
  else {
  	puts("1");
  	printf("%lld\n", 1ll * fact[0] * fact[1]);
  }

  return 0;
}
