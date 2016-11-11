#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a, b;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	a.clear();
    	b.clear();
    	
    	int n;
    	cin >> n;
    	
    	for(int i = 0; i < n; i++) {
    		int tmp;
    		cin >> tmp;
    		a.push_back(tmp);
    		b.push_back(tmp);
    	}
    	
    	sort(b.begin(), b.end());
    	reverse(b.begin(), b.end());
    	
    	int c = 0;
    	for(int i = 0; i < n; i++)
    		if(a[i] != b[i])
    			c++;
    			
    	cout << n - c << endl;
    }
    
    return 0;
}
