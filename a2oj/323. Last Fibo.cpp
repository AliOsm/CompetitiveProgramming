#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int arr[1001];
vector<int> res;

int main() {
    int t, tmp;
    
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i <= 1000; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000;
    
    cin >> t;
    
    while(t--) {
        res.clear();
        
        cin >> tmp;
        
        for(int i = 0; i <= 1000; i++)
            if(tmp == arr[i])
                res.push_back(i);
        
        if(res.empty())
            cout << "These digits seem to be invalid" << endl;
        else {
            cout << "The last three digits of ";
            
            for(int i = 0; i < res.size(); i++) {
                cout << "F(" << res[i] << ")";
                
                if(i < res.size() -1) cout << ", ";
            }
            
            cout << " are [" << tmp << ']' << endl;
        }
    }
    
    return 0;
}
