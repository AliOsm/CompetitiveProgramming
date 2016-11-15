#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

vector<string> arr;

int main() {
    int n;
    
    cin >> n;
    
    while(true) {
    	if(!n) break;
    	
    	arr.clear();
    	string s;
    	int max = 0;
    	
    	while(n--) {
    		cin >> s;
    		if(s.length() > max) max = s.length();
    		arr.push_back(s);
    	}

    	for(int i = 0, len = arr.size(); i < len; i++)
    		cout << setw(max) << arr[i] << endl;
    	
    	cin >> n;
    	if(n) cout << endl;
    }
    
    return 0;
}
