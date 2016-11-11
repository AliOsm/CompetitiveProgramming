#include <iostream>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

map<int, int> m;

int main() {
	int count = 1;
    while(true) {
    	m.clear();
    	
    	int n;
    	cin >> n;
    	if(!n) break;
    	
    	double total_p = 0, total_c = 0;
    	while(n--) {
    		int p, c;
    		cin >> p >> c;
    		
    		m[c / p] += p;

    		total_p += p;
    		total_c += c;
    	}

    	cout << "Cidade# " << count++ << ':' << endl;
    	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    		cout << it->second << '-' << it->first << ' ';
    	cout << endl << fixed << setprecision(2) << "Consumo medio: " << floor(total_c / total_p * 100) / 100 << " m3." << endl << endl;
    }
    
    return 0;
}
