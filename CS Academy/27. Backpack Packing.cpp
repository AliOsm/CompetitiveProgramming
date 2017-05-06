#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    int cnt = n;
    for(int i = 0; i < n; ++i) {
        if(a >= b && a >= arr[i]) {
            --cnt;
            a -= arr[i];
        } else if(b >= a && b >= arr[i]) {
            --cnt;
            b -= arr[i];
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}

