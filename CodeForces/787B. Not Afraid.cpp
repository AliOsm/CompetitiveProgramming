#include <iostream>
#include <set>

using namespace std;

multiset<int> rick, morty;
multiset<int>::iterator it;

int main() {
  bool ok = true;
  
  int n, m;
  cin >> n >> m;
  
  int a, b;
  for(int i = 0; i < m; i++) {
    rick.clear();
    morty.clear();
    
    cin >> a;
    
    for(int j = 0; j < a; j++) {
      cin >> b;
      
      if(b >= 0) {
        it = rick.find(-b);
        if(it != rick.end()) rick.erase(it);
        else morty.insert(b);
      } else {
        it = morty.find(-b);
        if(it != morty.end()) morty.erase(it);
        else rick.insert(b);
      }
    }
    
    if(rick.size() + morty.size() == a) ok = false;
  }
  
  if(ok) cout << "NO" << endl;
  else cout << "YES" << endl;
  
  return 0;
}

