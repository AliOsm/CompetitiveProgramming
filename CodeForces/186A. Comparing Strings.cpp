#include <bits/stdc++.h>

using namespace std;

int fr[26];
string a, b;

int main() {
  cin >> a >> b;

  if(a.length() != b.length()) {
    puts("NO");
    return 0;
  }

  int cnt = 0;
  for(int i = 0; i < a.length(); ++i)
    if(a[i] != b[i])
      ++cnt, ++fr[a[i] - 'a'], ++fr[b[i] - 'a'];
  
  if(cnt != 2) {
    puts("NO");
  } else {
    bool ok = true;
    for(int i = 0; i < 26; ++i)
      if(fr[i] % 2 != 0)
        ok = false;
    if(ok)
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
