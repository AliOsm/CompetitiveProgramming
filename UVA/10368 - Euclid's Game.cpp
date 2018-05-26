/*
  Idea:
    - We can write a Dynamic Programming solution to find a pattern.
    - The pattern will be as follows:
      Ollie always wins till a spicific point then always Stan wins.
    - Then we can take the pattern sequence and uning OEIS we can find
      the equation for it.
*/

#include <bits/stdc++.h>

using namespace std;

long long n, m;

int main() {
  long double tau = (1 + sqrt(5)) / 2;
  while(scanf("%lld %lld", &n, &m) && n != 0 && m != 0) {
  	if(n == m) {
  		puts("Stan wins");
  		continue;
  	}

  	if(n > m)
  		swap(n, m);

  	// a(n) = floor((n + 1) * tau) - n - 1
  	int res = floor(1.0 * (n + 1) * tau) - n - 1;
  	if(n + res >= m)
  		puts("Ollie wins");
  	else
  		puts("Stan wins");
  }

  return 0;
}
