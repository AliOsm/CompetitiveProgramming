#include <iostream>
#include <string>
#include <cctype>
 
using namespace std;
 
int main() {
  string n1, n2;
  cin >> n1 >> n2;
  
  if(n1.length() < n2.length()) {
    cout << "LESS" << endl;
    return 0;
  } else if(n1.length() > n2.length()) {
    cout << "GREATER" << endl;
    return 0;
  } else {
    for(int i = 0; i < n1.length(); i++)
      if((n1[i] - '0') > (n2[i] - '0')) {
        cout << "GREATER" << endl;
        return 0;
      } else if((n1[i] - '0') < (n2[i] - '0')) {
        cout << "LESS" << endl;
        return 0;
      }
  }
  
  cout << "EQUAL" << endl;
 
  return 0;
}
