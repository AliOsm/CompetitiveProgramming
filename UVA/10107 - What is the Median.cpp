#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int const N = 10001;
    int arr[N], n;
    
    for(int i = 0; cin >> arr[i]; i++) {
        sort(arr, arr + i + 1);
        
        if(i % 2 == 0) cout << arr[i / 2] << endl;
        else cout << (arr[i / 2] + arr[(i / 2) + 1]) / 2 <<  endl;
    }
    
    return 0;
}
