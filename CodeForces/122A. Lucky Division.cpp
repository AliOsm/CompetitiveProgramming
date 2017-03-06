#include <iostream>

using namespace std;

int lucky[] = {4, 7, 44, 47, 74, 77, 444, 777, 474, 747, 447, 774, 744, 477};

int main() {
    int n, i;
    cin >> n;
    
    for(i = 0; i < 14; i++)
        if(n == lucky[i] || n % lucky[i] == 0) {
            cout << "YES" << endl;
            break;
        }
    
    if(i == 14) cout << "NO" << endl;
    
    return 0;
}
