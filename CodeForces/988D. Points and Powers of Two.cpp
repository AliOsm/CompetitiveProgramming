/*
  Idea:
    - Brute force.
    - Based on the fact says we can't have more than 3 numbers with powers
      of two as subtraction values between any of them, then we can do the
      brute force.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n;
long long a[N], powers[35];
vector<long long> sol, tmp;

bool check(long long x) {
	for(int i = 0; i < tmp.size(); ++i)
		if(!binary_search(powers, powers + 31, abs(tmp[i] - x)))
			return false;
	return true;
}

int main() {
  powers[0] = 1;
  for(int i = 1; i < 31; ++i)
  	powers[i] = powers[i - 1] * 2;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
  	scanf("%lld", a + i);
  sort(a, a + n);

  for(int i = 0; i < n; ++i) {
  	long long cur = a[i];
  	tmp.push_back(cur);
  	for(int j = 0; j < 31; ++j) {
  		if(binary_search(a, a + n, cur + powers[j]) && check(cur + powers[j]))
  			tmp.push_back(cur + powers[j]);
  		if(binary_search(a, a + n, cur - powers[j]) && check(cur - powers[j]))
  			tmp.push_back(cur - powers[j]);
  	}

  	if(tmp.size() > sol.size())
  		sol.swap(tmp);
  	tmp.clear();
  }

 	printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
  	printf("%s%lld", i == 0 ? "" : " ", sol[i]);
  puts("");

  return 0;
}
