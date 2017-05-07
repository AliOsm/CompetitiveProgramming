#include <iostream>

using namespace std;

int const N = 1e5 + 1;
int freq[N];

int main() {
  int n, m;
  cin >> n >> m;

  int a, b;
  for(int i = 0; i < m; ++i) {
    cin >> a >> b;
    ++freq[--a];
    ++freq[--b];
  }

  for(int i = 0; i < n; ++i)
    if(freq[i] % 2 != 0) {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl;

  return 0;
}
