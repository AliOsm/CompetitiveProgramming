#include <iostream>

using namespace std;

int main() {
  int n, size = 0, res = 0;;
  cin >> n;
  
  int tmp;
  while(n--) {
    cin >> tmp;
    if(tmp) {
      size++;
    } else {
      if(size)
	size--;
    }
    
    res = max(res, size);
  }
  
  cout << res << endl;
  
  return 0;
}

