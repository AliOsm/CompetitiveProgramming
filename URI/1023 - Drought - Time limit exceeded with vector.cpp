#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int> > > arr;

int main() {
	int count = 1;
    while(true) {
    	arr.clear();
    	
    	int n;
    	cin >> n;
    	if(!n) break;
    	
    	double total_p = 0, total_c = 0;
    	while(n--) {
    		int p, c;
    		cin >> p >> c;
    		
    		arr.push_back(make_pair(c / p, make_pair(p, c)));
    		
    		total_p += p;
    		total_c += c;
    	}
    	
    	sort(arr.begin(), arr.end());
    	
    	for(int i = 0, len = arr.size() - 1; i < len; i++)
    		if(arr[i].first == arr[i+1].first) {
    			arr[i].second.first += arr[i+1].second.first;
    			arr.erase(arr.begin() + i+1);
    			len--;
    			i--;
    		}
    	
    	cout << "Cidade# " << count++ << ':' << endl;
    	for(int i = 0, len = arr.size(); i < len; i++)
    		cout << arr[i].second.first << '-' << arr[i].first << ' ';
    	cout << endl << fixed << setprecision(2) << "Consumo medio: " << floor(total_c / total_p * 100) / 100 << " m3." << endl << endl;
    }
    
    return 0;
}
