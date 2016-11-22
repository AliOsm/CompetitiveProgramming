#include <iostream>

using namespace std;

int arr[10001];

int main() {
	int n;
	
	while(cin >> n) {
		for(int i = 0; i < 101; i++) arr[i] = 0;
		
		for(int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			for(int j = a; j <= b; j++)
				arr[j]++;
		}
		
		int m;
		cin >> m;
		
		if(!arr[m])
			cout << m << " not found" << endl;
		else {
			int c = 0;
			for(int i = 0; i < m; i++) c += arr[i];
			cout << m << " found from " << c << " to " << c + arr[m] - 1 << endl;
		}
	}
    
  return 0;
}
