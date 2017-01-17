#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    cout << "Lumberjacks:" << endl;
    
    while(t--) {
        int arr[10];
        for(int i = 0; i < 10; i++) cin >> arr[i];
        
        bool a = false;
        if(arr[0] < arr[1]) a = true;
        
        if(a) {
            a = true;
            for(int i = 0; i < 9; i++)
                if(arr[i] > arr[i+1]) {
                    a = false;
                    break;
                }
        } else {
            a = true;
            for(int i = 0; i < 9; i++)
                if(arr[i] < arr[i+1]) {
                    a = false;
                    break;
                }
        }
        
        if(a) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }
    
    return 0;
}
