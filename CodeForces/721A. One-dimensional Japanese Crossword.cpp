#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> res;
    int n, blacks = 0, count = 0;
    string s;
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) {
    	if(s[i] == 'B') {
    		blacks++;
    		
    		while(s[i] == 'B') {
    			count++;
    			i++;
    		}
    		
    		res.push_back(count);
    	}
    	
    	if(s[i] == 'W')
    		count = 0;
    }
    
    cout << blacks << endl;
    
    if(res.size())
    	for(int i = 0; i < res.size(); i++)
    		cout << res[i] << ' ';
    
    cout << endl;
}
