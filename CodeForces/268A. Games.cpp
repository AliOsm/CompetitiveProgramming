#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > arr;

int main() {
		int n, a, b, c = 0;
		cin >> n;
	
		for(int i = 0; i < n; i++) {
	  	  cin >> a >> b;
	  	  arr.push_back(make_pair(a, b));
		}
	
		for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && arr[i].first == arr[j].second) c++;
	   
  	cout << c << endl;

		return 0;
}
