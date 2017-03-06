#include <iostream>

using namespace std;

int main() {
  int k, n, w;
  cin >> k >> n >> w;
  
  long long res = 0;
  
  for(int i = 1; i <= w; i++)
      res += k * i;
    
    if(res <= n)
        cout << 0 << endl;
    else
        cout << res - n << endl;

  
  return 0;
}
