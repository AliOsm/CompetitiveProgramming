#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int> > arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
        
        int res = abs(abs(arr[0].first) - abs(arr[0].second));
        
        bool f = true;
        
        for(int i = 0; i < n; i++)
            if(abs(abs(arr[i].first) - abs(arr[i].second)) != res) {
                f = false;
                break;
            }
        
        if(f) cout << "yes" << endl;
        else cout << "no" << endl;
        
        if(t) cout << endl;
    }
    
    return 0;
}
