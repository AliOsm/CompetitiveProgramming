#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct company {
    string name;
    int low, high;
};

vector<company> arr;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int c;
        cin >> c;
        
        arr.clear();
        arr.resize(c);
        
        for(int i = 0; i < c; i++)
            cin >> arr[i].name >> arr[i].low >> arr[i].high;
        
        int q;
        cin >> q;
        
        while(q--) {
            int tmp, cc = 0, indx = 0;
            cin >> tmp;
            
            for(int i = 0; i < c; i++)
                if(arr[i].low <= tmp && arr[i].high >= tmp) {
                    cc++;
                    indx = i;
                }
            
            if(cc == 1) cout << arr[indx].name << endl;
            else cout << "UNDETERMINED" << endl;
        }
        
        if(t) cout << endl;
    }
    
    return 0;
}
