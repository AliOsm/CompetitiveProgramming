#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int c = 0, cc = 0;
    for(int i = 0; i < n; i++)
    	if(s[i] == 'D') c++;
    	else cc++;
    
    if(c == cc)
    	cout << "Friendship" << endl;
    else if(c > cc)
    	cout << "Danik" <<endl;
    else
    	cout << "Anton" << endl;
    
    return 0;
}
