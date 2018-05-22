/*
	Idea:
		- We can solve this problem using Dynaimc Programming.
		- dp[i] means the longest subsequence in the array end with the number i.
		- Then we can maximize the dp[i] while we iterate over the array:
			dp[i] = dp[i - 1] + 1
		- The answer will be the maximum element in the dp array.
		- Finally to construct the indexes to output them we can iterate over the
			array again fron end to begin and if we find the value of the max index
			we push it in vector and subtract 1 from the max index.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;
int n, a[N];
vector<int> all, sol;
map<int, int> dp;

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> a[i];
  
  int mx = 0, val;
  for(int i = 0; i < n; ++i) {
  	dp[a[i]] = dp[a[i] - 1] + 1;
  	if(dp[a[i]] > mx)
  		mx = dp[a[i]], val = a[i];
  }

  cout << mx << endl;
  for(int i = n - 1; i >= 0; --i)
  	if(a[i] == val) {
  		sol.push_back(i + 1);
  		--val;
  	}

  reverse(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); ++i)
  	cout << sol[i] << ' ';
  cout << endl;

  return 0;
}
