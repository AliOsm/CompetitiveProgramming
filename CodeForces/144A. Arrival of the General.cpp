#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
    int n, mx = 0, mn = 101, indxmx, indxmn;
    cin >> n;
    
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        
        if(arr[i] > mx) {
            mx = arr[i];
            indxmx = i;
        }
        
        if(arr[i] <= mn) {
            mn = arr[i];
            indxmn = i;
        }
    }

    if(indxmx > indxmn)
        cout << indxmx + arr.size() - indxmn - 2 << endl;
    else
        cout << indxmx + arr.size() - indxmn - 1 << endl;

    return 0;
}
