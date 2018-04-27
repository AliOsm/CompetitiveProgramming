#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int n, a[N], sol[N];

int main() {
	cin >> n;
  for(int i = 0; i < n - 1; ++i)
    cin >> a[i];
  
  sol[n - 1] = 9;
  for(int i = n - 2; i >= 0; --i) {
    if(a[i] == -1) {
      sol[i] = sol[i + 1] - 1;
      if(sol[i] < 0) {
        puts("-1");
        return 0;
      }
    } else if(a[i] == 0) {
      sol[i] = sol[i + 1];
    } else {
      sol[i] = sol[i + 1] + 1;
      if(sol[i] == 10) {
        for(int j = i; j < n; ++j) {
          --sol[j];
          if(sol[j] < ) {
          	puts("-1");
          	return 0;
          }
          
          if(a[j] == -1) {
            if(j + 1 < n && sol[j] < sol[j + 1])
              break;
          } else if(a[j] == 0) {
            if(j + 1 < n && sol[j] == sol[j + 1])
              break;
          } else if(j + 1 < n) {
            if(sol[j] > sol[j + 1])
              break;
          }
        }
      } else
      	sol[i] = 9;
    }
  }

  if(sol[0] == 0) {
  	puts("-1");
  	return 0;
  }
  
	for(int i = 0; i < n; ++i)
    cout << sol[i];
  puts("");

  return 0;
}
