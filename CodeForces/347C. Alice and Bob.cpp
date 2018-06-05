/*
  Idea:
    - Calculate the GCD of all elements in the array.
    - While you doing the subtractions, at the end you will get the GCD
      multiples as array elements.
    - Calculate the number of GCD multiples do not exist in the array,
      and based on the number you can decide who is the winner.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, mx = 0, gcd = 0;
  cin >> n;
  for(int i = 0, tmp; i < n; ++i)
  	cin >> tmp, mx = max(mx, tmp), gcd = __gcd(gcd, tmp);
  mx /= gcd;

  if((mx - n) % 2 == 0)
  	puts("Bob");
  else
  	puts("Alice");

  return 0;
}
