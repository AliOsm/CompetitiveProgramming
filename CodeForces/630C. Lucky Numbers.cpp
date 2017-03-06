#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	unsigned long long counter = 0;
	
	for(int i = 1; i <= n; i++)
		counter += 1LL << i;

	cout << counter << endl;
    
  return 0;
}
