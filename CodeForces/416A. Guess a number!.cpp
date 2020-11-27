#include <bits/stdc++.h>

using namespace std;

int n, mn = -2e9, mx = 2e9;

int main() {
  cin >> n;

  string op;
  int num;
  char ans;
  for(int i = 0; i < n; ++i) {
    cin >> op >> num >> ans;

    if(op == ">") {
      if(ans == 'Y')
        mn = max(mn, num + 1);
      else
        mx = min(mx, num);
    }

    if(op == "<") {
      if(ans == 'Y')
        mx = min(mx, num - 1);
      else
        mn = max(mn, num);
    }

    if(op == ">=") {
      if(ans == 'Y')
        mn = max(mn, num);
      else
        mx = min(mx, num - 1);
    }

    if(op == "<=") {
      if(ans == 'Y')
        mx = min(mx, num);
      else
        mn = max(mn, num + 1);
    }
  }

  if(mn > mx)
    puts("Impossible");
  else {
    cout << mn << endl;
  }

  return 0;
}
