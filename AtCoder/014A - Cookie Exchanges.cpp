#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int res = 0, lol = 1;
  while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    if(lol == 1e6 + 1) {
      cout << -1 << endl;
      return 0;
    }

    int tmpa = a / 2;
    int tmpb = b / 2;
    int tmpc = c / 2;

    a = tmpb + tmpc;
    b = tmpa + tmpc;
    c = tmpa + tmpb;

    res++;
    lol++;
  }

  cout << res << endl;

  return 0;
}
