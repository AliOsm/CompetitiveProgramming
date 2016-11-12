#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> c1s1, c1s2, c1s3, c2s1, c2s2, c2s3;

int main() {
	int n;
    cin >> n;
    
    while(true) {
    	if(!n) break;
    	
    	c1s1.clear();
    	c1s2.clear();
    	c1s3.clear();
    	c2s1.clear();
    	c2s2.clear();
    	c2s3.clear();
    	
    	for(int i = 0; i < n; i++) {
    		string name, color;
    		char size;
    		
    		cin.ignore();
    		getline(cin, name);
    		cin >> color >> size;
    		
    		if(color == "branco") {
    			if(size == 'P')
    				c1s1.push_back(name);
    			else if(size == 'M')
    				c1s2.push_back(name);
    			else if(size == 'G')
    				c1s3.push_back(name);
    		} else {
    			if(size == 'P')
    				c2s1.push_back(name);
    			else if(size == 'M')
    				c2s2.push_back(name);
    			else if(size == 'G')
    				c2s3.push_back(name);
    		}
    	}
    	
    	sort(c1s1.begin(), c1s1.end());
    	sort(c1s2.begin(), c1s2.end());
    	sort(c1s3.begin(), c1s3.end());
    	sort(c2s1.begin(), c2s1.end());
    	sort(c2s2.begin(), c2s2.end());
    	sort(c2s3.begin(), c2s3.end());
    	
    	for(int i = 0, len = c1s1.size(); i < len; i++)
    		cout << "branco P " << c1s1[i] << endl;
    	for(int i = 0, len = c1s2.size(); i < len; i++)
    		cout << "branco M " << c1s2[i] << endl;
    	for(int i = 0, len = c1s3.size(); i < len; i++)
    		cout << "branco G " << c1s3[i] << endl;
    	for(int i = 0, len = c2s1.size(); i < len; i++)
    		cout << "vermelho P " << c2s1[i] << endl;
    	for(int i = 0, len = c2s2.size(); i < len; i++)
    		cout << "vermelho M " << c2s2[i] << endl;
    	for(int i = 0, len = c2s3.size(); i < len; i++)
    		cout << "vermelho G " << c2s3[i] << endl;
    	
    	cin >> n;
    	
    	if(n)
    		cout << endl;
    }
    
    return 0;
}
