#include <bits/stdc++.h>

using namespace std;

string s, tmp;
vector<int> sol;

int main() {
  cin >> s;

  for(int i = 0; i < s.length(); ++i) {
    if(i + 1 < s.length() && s[i] == 'b' && s[i + 1] == 'a') {
      reverse(s.begin(), s.begin() + i);
      sol.push_back(i);
      continue;
    }

    if(i + 1 < s.length() && s[i] == 'a' && s[i + 1] == 'b' ||
      i == s.length() - 1 && s[i] == 'a') {
      reverse(s.begin(), s.begin() + i);
      sol.push_back(i);
    }
  }

  for(int i = 0; i < s.length(); ++i) {
    if(binary_search(sol.begin(), sol.end(), i))
      printf("1 ");
    else
      printf("0 ");
  }
  puts("");

  return 0;
}
