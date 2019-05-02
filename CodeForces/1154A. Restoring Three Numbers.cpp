#include <bits/stdc++.h>

using namespace std;

int x[4];

int main() {
  for(int i = 0; i < 4; ++i)
    scanf("%d", x + i);
  
  sort(x, x + 4);

  do {
    int ab = x[0];
    int ac = x[1];
    int bc = x[2];
    int sum = x[3];

    int a = (ab - bc + ac) / 2;
    int b = (bc - ac + ab) / 2;
    int c = (ac - ab + bc) / 2;

    if(a + b + c == sum) {
      // cout << ab << ' ' << ac << ' ' << bc << ' ' << sum << endl;
      printf("%d %d %d", a, b, c);
      return 0;
    }
  } while(next_permutation(x, x + 4));

  return 0;
}
