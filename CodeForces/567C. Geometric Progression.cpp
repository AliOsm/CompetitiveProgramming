/*
	Idea:
		- For each index i try to make it the middle of the progression, then find
			how many element before it equal to `a[i] / k` and how many element after
			it equal to `a[i] * k`, finally in each step update the result by multiply
			the number of elements before and after.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, k, arr[N];
map<long long, vector<int> > mp;

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
  	cin >> arr[i];
  	mp[arr[i]].push_back(i);
  }

  long long res = 0;
  for(int i = 1; i < n - 1; ++i) {
  	if(arr[i] % k != 0)
  		continue;

  	long long a = arr[i] / k, b = arr[i], c = 1ll * arr[i] * k;

  	if(mp.count(a) != 1 || mp.count(c) != 1)
  		continue;

  	int acnt = upper_bound(mp[a].begin(), mp[a].end(), i) - mp[a].begin(),
  			ccnt = upper_bound(mp[c].begin(), mp[c].end(), i) - mp[c].begin();

  	if(a == b && b == c)
  		--acnt;

  	res += 1ll * acnt * (mp[c].size() - ccnt);
  }

  cout << res << endl;

  return 0;
}
