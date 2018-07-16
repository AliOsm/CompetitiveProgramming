#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int r1 = max((3 * a) / 10, a - (a / 250) * c);
  int r2 = max((3 * b) / 10, b - (b / 250) * d);

  if(r1 > r2)
    puts("Misha");
  else if(r1 < r2)
    puts("Vasya");
  else
    puts("Tie");

  return 0;
}
