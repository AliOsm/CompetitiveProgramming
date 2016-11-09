#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    cout << "Total: R$ ";
    
    if(a == 1)
    	printf("%0.2f", 4.0 * b);
    else if(a == 2)
    	printf("%0.2f", 4.5 * b);
    else if(a == 3)
    	printf("%0.2f", 5.0 * b);
    else if(a == 4)
    	printf("%0.2f", 2.0 * b);
    else if(a == 5)
    	printf("%0.2f", 1.5 * b);
    
    cout << endl;
    
    return 0;
}
