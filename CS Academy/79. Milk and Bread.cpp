#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a > b)
        swap(a, b);
    
    cout << min(abs(c - b) + abs(b - a), abs(c - a) + abs(b - a)) << endl;
    
    return 0;
}
