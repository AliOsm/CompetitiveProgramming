/*
	Idea:
		- Brute force.
		- For each string try to put it in the last of the sorted list, we can do
			this by trying to find the string which is contains the other strings
			as substrings.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
bool vis[101];
string s[101];
vector<string> sol;

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> s[i];

  for(int k = 0; k < 100; ++k) {
	  for(int i = 0; i < n; ++i) {
	  	if(vis[i])
	  		continue;
	  	bool ok = true;
	  	for(int j = 0; j < n; ++j) {
	  		if(i == j || vis[j])
	  			continue;

	  		if(s[i].find(s[j]) == string::npos) {
	  			ok = false;
	  			break;
	  		}
	  	}
	  	if(ok) {
	  		sol.push_back(s[i]);
	  		vis[i] = true;
	  	}
	  }
	}

  if(sol.size() != n)
  	cout << "NO" << endl;
  else {
  	cout << "YES" << endl;
  	for(int i = sol.size() - 1; i >= 0; --i)
  		cout << sol[i] << endl;
  }

  return 0;
}
