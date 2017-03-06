#include <iostream>
#include <string>

using namespace std;

int const N = 1e5 + 1;
int cum[N];

int main() {
  string s;
  cin >> s;

  cum[0] = 0;
  for(int i = 1; i < s.length(); i++) {
    if(s[i] == s[i-1]) cum[i] = cum[i-1] + 1;
    else cum[i] = cum[i-1];
  }

  int q;
  cin >> q;

  int a, b;
  while(q--) {
    cin >> a >> b;
    a--; b--;

    cout << cum[b] - cum[a] << endl;
  }
}

