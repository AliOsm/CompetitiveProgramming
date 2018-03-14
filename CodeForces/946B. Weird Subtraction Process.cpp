#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  bool ok1 = true, ok2 = true;
  while(a != 0 && b != 0 && (ok1 || ok2)) {
  	ok1 = ok2 = false;

  	if(a >= 2 * b && a - 2 * b >= 0) {
  		ok1 = true;
  		a -= (a / (2 * b)) * 2 * b;
  		continue;
  	}

  	if(b >= 2 * a && b - 2 * a >= 0) {
  		ok2 = true;
  		b -= (b / (2 * a)) * 2 * a;
  		continue;
  	}
  }

  cout << a << ' ' << b << endl;

  return 0;
}