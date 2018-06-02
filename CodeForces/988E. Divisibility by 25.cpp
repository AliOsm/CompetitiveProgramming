/*
  Idea:
    - Brute force.
    - The number divisible by 25 if the last two digits of it divisible by
      25.
    - Put the digits of the number in a vector and search for any combination
      "00", "25", "50" or "75" and try to swap them to the end of the number
      and minimize the result.
*/

#include <bits/stdc++.h>

using namespace std;

int m;
long long n;
vector<int> all, tmp;

int main() {
  scanf("%lld", &n);
  while(n != 0) {
  	all.push_back(n % 10);
  	n /= 10;
  }
  reverse(all.begin(), all.end());
  m = all.size();

  int res = 1000;
  for(int i = 0; i < all.size(); ++i) {
  	for(int j = 0; j < all.size(); ++j) {
  		if(i == j)
  			continue;

  		if(all[i] == 0 && all[j] == 0) {
  			res = min(res, m - i + m - j - 3);
  		} else if(all[i] == 2 && all[j] == 5 ||
  							all[i] == 5 && all[j] == 0 ||
  							all[i] == 7 && all[j] == 5) {
  			int tmp = m - i + m - j - 2 - (i < j), idx = -1;
  			for(int k = 0; k < all.size(); ++k)
  				if(all[k] == 0) {
  					idx = k;
  					break;
  				}
  			if(idx != j && idx != -1 && ((i == 0 && idx == 1) || (i == 0 && j == 1 && idx == 2) || (j == 0 && idx == 1))) {
  				for(int k = idx + 1; k < all.size(); ++k)
  					if(all[k] != 0) {
  						idx = k;
  						break;
  					}
  				if(all[idx] == 0)
  					tmp = 1e9;
  				else
  					tmp += idx - (j == 1 ? 2 : 1);
  			}
  			res = min(res, tmp);
  		}
  	}
  }

  if(res == 1000)
  	puts("-1");
  else
  	printf("%d\n", res);

  return 0;
}
