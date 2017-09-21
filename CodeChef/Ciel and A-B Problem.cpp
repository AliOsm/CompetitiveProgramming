#include <bits/stdc++.h>

using namespace std;

string toString(int n) {
  string tmp = "";
  while(n) {
    tmp += (n % 10) + '0';
    n /= 10;
  }
  reverse(tmp.begin(), tmp.end());
  return tmp;
}

int main() {
  int a, b;
  cin >> a >> b;
  string c = toString(a - b);
  if(c[c.length() - 1] == '9')
    c[c.length() - 1] = '1';
  else
    c[c.length() - 1] = '9';
  cout << c << endl;
}

