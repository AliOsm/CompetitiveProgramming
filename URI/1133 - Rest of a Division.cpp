#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long x, y;
	cin >>x >> y;
	
	long long n = min(x, y);
	long long m = max(x, y);
	for(int i = n + 1; i < m; i++) {
		if(i % 5 == 2 || i % 5 == 3)
			cout<<i<<endl;
	}
    
	return 0;
}
