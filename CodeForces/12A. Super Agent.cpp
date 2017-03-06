#include <iostream>
#include <string>

using namespace std;

string arr[3];

int main() {
    for(int i = 0; i < 3; i++) cin >> arr[i];
    reverse(arr[2].begin(), arr[2].end());
    
    if(arr[1][0] == arr[1][2] && arr[0] == arr[2]) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
