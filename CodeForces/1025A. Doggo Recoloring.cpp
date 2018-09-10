/*
  Idea:
    - Implementation, Frequency array.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  cin >> n >> s;

  if(n == 1) {
    puts("Yes");
    return 0;
  }

  int fr[26] = {0};
  for(int i = 0; i < n; ++i)
    ++fr[s[i] - 'a'];

  for(int i = 0; i < 26; ++i)
    if(fr[i] > 1) {
      puts("Yes");
      return 0;
    }

  puts("No");

  return 0;
}
