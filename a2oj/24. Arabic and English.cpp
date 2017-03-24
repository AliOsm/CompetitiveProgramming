#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v1, v2;

int main() {
  bool be_af;
  
  int t;
  cin >> t;
  
  int n;
  string s, tmp;
  while(t--) {
    s = "";
    v1.clear();
    v2.clear();
    be_af = false;
    
    cin >> n;
    
    while(n--) {
      cin >> tmp;
      
      if(!be_af && tmp[0] == '#') v1.push_back(tmp);
      if(be_af && tmp[0] == '#') v2.push_back(tmp);
      if(tmp[0] != '#') {
        s = tmp;
        be_af = true;
      }
    }
    
    for(int i = 0; i < v2.size(); i++) {
      if(i) cout << ' ';
      cout << v2[i];
    }
    
    if(s != "" && v2.size()) cout << ' ' << s;
    else cout << s;
    
    if(s != "" || v2.size())
      for(int i = 0; i < v1.size(); i++) 
        cout << ' ' << v1[i];
    else if(s == "")
      for(int i = 0; i < v1.size(); i++) {
        if(i) cout << ' ';
        cout << v1[i];
      }
    
    cout << endl;
  }
  
  return 0;
}

