#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int arr[3];
    for(int i = 1; t--; i++) {
        for(int i = 0; i < 3; i++) cin >> arr[i];
        sort(arr, arr + 3);
        cout << "Case " << i << ": " << arr[1] << endl;
    }
    
    return 0;
}
