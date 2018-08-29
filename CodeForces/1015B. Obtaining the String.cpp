/*
  Idea:
    - Greedy.
    - In each time try to set the most last character in the
      string `s` to the same character in the same position in
      string `t`.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;
vector<int> sol;

int main() {
  cin >> n;
  cin >> s >> t;

  for(int i = n - 1; i >= 0; --i) {
    if(s[i] == t[i])
      continue;

    int lst = -1;
    for(int j = 0; j < i; ++j)
      if(s[j] == t[i])
        lst = j;

    for(int j = lst; j < i; ++j) {
      swap(s[j], s[j + 1]);
      sol.push_back(j + 1);
    }
  }

  if(s != t) {
    puts("-1");
    return 0;
  }

  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%d ", sol[i]);
  puts("");

  return 0;
}
