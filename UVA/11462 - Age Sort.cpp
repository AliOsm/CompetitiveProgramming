#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
    int n;
    
    while(cin >> n) {
        if(!n) break;
        arr.clear();
        arr.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            cout << arr[i];
            if(i + 1 != n) cout << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
