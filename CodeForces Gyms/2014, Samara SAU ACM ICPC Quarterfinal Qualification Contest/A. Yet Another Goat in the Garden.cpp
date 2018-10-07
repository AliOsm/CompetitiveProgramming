#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a, b;

int main() {
  int x, y, z, r;
  cin >> x >> y >> z >> r;

  double side = (x + y + z) / 2.0;
  double area = sqrt(side * (side - x) * (side - y) * (side - z));
  double rr = area / side;
  double NR = r / rr;
  double done = NR * NR * (area - acos(-1) * rr * rr);
  printf("%.9lf\n", ((area - done) / area));

  return 0;
}
