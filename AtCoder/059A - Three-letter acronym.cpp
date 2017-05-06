#include <iostream>
#include <string>
#include <cctype>
 
using namespace std;
 
int main() {
  string s;
  for(int i = 0; i < 3; i++) {
    cin >> s;
    cout << char(toupper(s[0]));
  }
  cout << endl;
 
  return 0;
}
