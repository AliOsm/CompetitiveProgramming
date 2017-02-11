#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, arr[51], h, l;
    for(int i = 1; t--; i++) {
        h = l = 0;
        cin >> n;
        for(int j = 0; j < n; j++) cin >> arr[j];
        
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] < arr[j+1]) h++;
            else if(arr[j] > arr[j+1]) l++;
        }
        
        cout << "Case " << i << ": " << h << ' ' << l << endl;
    }
    
    return 0;
}
