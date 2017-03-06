#include <iostream>
#include <algorithm>

using namespace std;

int arr[51];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + 51);
    reverse(arr, arr + 51);
    
    int plugs = 0;
    
    for(int i = 0; k < m && i < n; i++) {
        plugs++;
        k += arr[i] - 1;
    }
    
    if(k >= m)
        cout << plugs << endl;
    else
        cout << -1 << endl;
  
    return 0;
}

