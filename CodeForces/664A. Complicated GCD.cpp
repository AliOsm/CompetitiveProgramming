#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  
  if(s1 == s2)
    cout << s1 << endl;
  else
    cout << 1 << endl;
  
  return 0;
}

