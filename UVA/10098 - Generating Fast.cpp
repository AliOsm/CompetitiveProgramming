#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  
  string s;
  while(t--) {
    cin >> s;
    sort(s.begin(), s.end());
    
    cout << s << endl;
    while(next_permutation(s.begin(), s.end()))
      cout << s << endl;
    
    cout << endl;
  }
  
  return 0;
}

