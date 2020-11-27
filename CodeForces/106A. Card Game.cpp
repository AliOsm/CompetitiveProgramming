#include <bits/stdc++.h>

using namespace std;

string a, b, c;
string p = "6789TJQKA";

int main() {
  cin >> a >> b >> c;

  if(b[1] == a[0] && c[1] != a[0]) {
    puts("YES");
  } else if(b[1] != a[0] && c[1] == a[0]) {
    puts("NO");
  } else {
    if(b[1] != c[1]) {
      puts("NO");
    } else {
      int bp = p.find(b[0]);
      int cp = p.find(c[0]);

      if(bp > cp) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }

  return 0;
}
