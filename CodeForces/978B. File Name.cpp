#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  while(s.length() >= 3 && s.find("xxx") != string::npos) {
    int idx = s.find("xxx");
    s.erase(idx, 1);
  }

  cout << n - s.length() << endl;

  return 0;
}
