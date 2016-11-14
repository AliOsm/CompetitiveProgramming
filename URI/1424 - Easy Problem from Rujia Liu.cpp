#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int> > mp;

int main() {
    int n, m;
    
    while(cin >> n >> m) {
    	mp.clear();
    	
    	for(int i = 1; i <= n; i++) {
    		int tmp;
    		cin >> tmp;
    		mp[tmp].push_back(i);
    	}
    	
    	while(m--) {
    		int t1, t2;
    		cin >> t1 >> t2;
    		
    		if(t1 <= mp[t2].size())
    			cout << mp[t2][t1 - 1] << endl;
    		else
    			cout << 0 << endl;
    	}
    }
    
    return 0;
}
