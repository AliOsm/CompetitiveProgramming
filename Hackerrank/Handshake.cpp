#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << n * (n - 1) / 2 << endl;
    }
    
    return 0;
}
