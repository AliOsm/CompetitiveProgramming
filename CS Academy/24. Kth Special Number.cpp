#include <iostream>
#include <bitset>

using namespace std;

bitset<64> bs;

int main() {
  int k;
    cin >> k;
    
    int n = 0, ones;
    
    while(k) {
        n++;
        ones = 0;
        bs = n;
        
        for(int i = bs.size() - 1; i >= 0; i--)
          if(bs[i] && bs[i+1]) {
            ones = 2;
            break;
          }
        
        if(ones != 2) k--;
    }
    
    cout << n << endl;
  
  return 0;
}

