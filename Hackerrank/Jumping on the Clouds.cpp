#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
    int n;
    cin >> n;
    
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int res = -1;
    
    for(int i = 0; i < n; i++) {
        if(i+2 < n && arr[i+2] == 0)
            i++;
        res++;
    }
    
    cout << res << endl;
    
    return 0;
}
