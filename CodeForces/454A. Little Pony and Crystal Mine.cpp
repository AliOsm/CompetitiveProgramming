#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, space, ds;
    cin >> n;
    space = n / 2;
    
    for(int i = 0; i < n; i++) {
        ds = n - (space * 2);
        
        for(int j = 0; j < space; j++) cout << '*';
        for(int j = 0; j < ds; j++) cout << 'D';
        for(int j = 0; j < space; j++) cout << '*';
        cout << endl;
        
        if(i < n / 2) space--;
        else space++;
    }

	return 0;
}
