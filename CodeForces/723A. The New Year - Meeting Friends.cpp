#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, suma, sumb, sumc;
    cin >> a >> b >> c;
    
    suma = abs(a-b) + abs(a-c);
    sumb = abs(b-a) + abs(b-c);
    sumc = abs(c-a) + abs(c-b);
    
    cout << min(suma, min(sumb, sumc)) << endl;
    
    return 0;
}
