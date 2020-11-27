#include <bits/stdc++.h>

using namespace std;

string s, h, m;

bool not_palindrome() {
  return h[0] == m[1] && h[1] == m[0];
}

string add(string s) {
  if(s[1] == '9') {
    ++s[0];
    s[1] = '0';
  } else {
    ++s[1];
  }
  return s;
}

int main() {
  cin >> s;

  h = s.substr(0, 2);
  m = s.substr(3, 2);

  do {
    m = add(m);
    if(m == "60") {
      m = "00";
      h = add(h);
    }
    if(h == "24")
      h = "00";
  } while(!not_palindrome());

  cout << h << ':' << m << endl;

  return 0;
}
