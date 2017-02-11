#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, res, tmp;
    
    for(int i = 1; cin >> n && n; i++) {
        res = 0;
        
        while(n--) {
            cin >> tmp;
            
            if(tmp) res++;
            else res--;
        }
        
        cout << "Case " << i << ": " << res <<endl;
    }
    
    return 0;
}
