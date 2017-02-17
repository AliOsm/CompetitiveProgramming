#include <iostream>

using namespace std;

int main(){
    int a0, a1, a2, ac = 0;
    cin >> a0 >> a1 >> a2;

    int b0, b1, b2, bc = 0;
    cin >> b0 >> b1 >> b2;
    
    if(a0 != b0)
        if(a0 > b0) ac++;
        else bc++;
    
    if(a1 != b1)
        if(a1 > b1) ac++;
        else bc++;
    
    if(a2 != b2)
        if(a2 > b2) ac++;
        else bc++;
    
    cout << ac << ' ' << bc << endl;
    
    return 0;
}
