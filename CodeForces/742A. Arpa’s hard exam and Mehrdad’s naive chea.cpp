#include <iostream>

using namespace std;

int arr[4] = {6, 8, 4, 2};

int main() {
    int n;
    cin >> n;
    
    if(n == 0)
        cout << 1 << endl;
    else
        cout << arr[n % 4] << endl;
    
    return 0;
}
