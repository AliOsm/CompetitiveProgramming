#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  
  while(cin >> s && s != "#") {
    if(next_permutation(s.begin(), s.end()))
      cout << s << endl;
    else
      cout << "No Successor" << endl;
  }
  
  return 0;
}

