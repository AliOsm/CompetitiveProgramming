#include <iostream>

using namespace std;

int main() {
    int n, tmp, res;
    cin >> n;
    
    bool f = true;
    
    cin >> tmp;
    while(tmp % 2 == 0) tmp /= 2;
    while(tmp % 3 == 0) tmp /= 3;
    
    res = tmp;
    
    for(int i = 1; i < n; i++) {
      cin >> tmp;
      while(tmp % 2 == 0) tmp /= 2;
      while(tmp % 3 == 0) tmp /= 3;
      
      if(tmp != res)
        f = false;
    }
    
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
