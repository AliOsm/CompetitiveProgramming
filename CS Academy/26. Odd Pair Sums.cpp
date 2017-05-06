#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> arr;
stack<int> st;

int main() {
  int n;
  cin >> n;
  
  arr.resize(n);
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  
  int res = 0;
  
  for(int i = 0; i < n; i++) {
    if(st.empty()) {
      st.push(arr[i]);
      continue;
    }
    
    if(!st.empty() && ((st.top() % 2 == 0 && arr[i] % 2 == 1) || (st.top() % 2 == 1 && arr[i] % 2 == 0)))
      st.push(arr[i]);
    else
      res++;
  }
  
  cout << res << endl;
  
  return 0;
}
