#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n, m, c;
    
    while(cin >> n >> m) {
        c = 0;
        arr.clear();
        arr.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        for(int i = 0; i < arr.size(); i++)
            if(m >= arr[i]) {
                m -= arr[i];
                c++;
            } else break;
        
        cout << c << endl;
    }
    
    return 0;
}
