#include <bits/stdc++.h>

using namespace std;

int n;
long long fr[3][60];
string a, b, c;

int main() {
  cin >> n;
  cin >> a >> b >> c;

  for(int i = 0; i < a.length(); ++i) {
    if(islower(a[i]))
      ++fr[0][a[i] - 'a'];
    else
      ++fr[0][a[i] - 'A' + 26];
  }

  for(int i = 0; i < a.length(); ++i) {
    if(islower(b[i]))
      ++fr[1][b[i] - 'a'];
    else
      ++fr[1][b[i] - 'A' + 26];
  }

  for(int i = 0; i < a.length(); ++i) {
    if(islower(c[i]))
      ++fr[2][c[i] - 'a'];
    else
      ++fr[2][c[i] - 'A' + 26];
  }

  long long mx[3] = {0};
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 60; ++j)
      mx[i] = max(mx[i], fr[i][j]);

    if(mx[i] == a.length()) {
      if(n == 1)
        mx[i] -= 1;
      continue;
    }

    mx[i] += n;

    if(mx[i] > a.length())
      mx[i] = a.length();
  }

  if(mx[0] > mx[1] && mx[0] > mx[2])
    cout << "Kuro" << endl;
  else if(mx[1] > mx[0] && mx[1] > mx[2])
    cout << "Shiro" << endl;
  else if(mx[2] > mx[0] && mx[2] > mx[1])
    cout << "Katie" << endl;
  else
    cout << "Draw" << endl;

  return 0;
}
