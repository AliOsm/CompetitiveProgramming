#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int total = 0;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }
        
        double res = 1.0 * total / n;
        
        total = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] > res)
                total++;
        
        cout << fixed << setprecision(3) << 100.0 * total / n << '%' << endl;
    }
    
    return 0;
}
