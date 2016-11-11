#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

map<string, pair<double, int> > m;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	m.clear();
    	
    	int tmp;
    	
    	cin >> tmp;
    	while(tmp--) {
    		string s;
    		double p;
    		
    		cin >> s >> p;
    		m[s] = make_pair(p, 0);
    	}
    	
    	cin >> tmp;
    	while(tmp--) {
    		string s;
    		int p;
    		
    		cin >> s >> p;
    		m[s].second = p;
    	}
    	
    	cout << "R$ ";
    	
    	double total = 0;
    	
    	for(map<string, pair<double, int> >::iterator it = m.begin(); it != m.end(); it++)
    		total += it->second.first * it->second.second;
    		
    	cout << fixed << setprecision(2) << total << endl;
    }
    
    return 0;
}
