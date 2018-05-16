#include <iostream>

using namespace std;

int n, k;

int main() {
  cin >> n >> k;
  for(int i = 0; i < k; ++i) {
    if(n % 10 != 0)
      --n;
    else
      n /= 10;
  }
  cout << n << endl;
}
