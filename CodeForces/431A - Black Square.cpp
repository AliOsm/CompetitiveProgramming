#include <iostream>
#include <string>

using namespace std;

int main() {
    int a1, a2, a3, a4;
    int c1, c2, c3, c4;
    cin >> a1 >> a2 >> a3 >> a4;
    c1 = c2 = c3 = c4 = 0;
    
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '1') c1++;
        else if(s[i] == '2') c2++;
        else if(s[i] == '3') c3++;
        else if(s[i] == '4') c4++;
    
    cout << (c1 * a1) + (c2 * a2) + (c3 * a3) + (c4 * a4) << endl;

	return 0;
}
