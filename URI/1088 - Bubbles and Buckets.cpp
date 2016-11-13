#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr;

int main() {
	while (true) {
		int n;
		scanf("%i", &n);
		
		if(!n) break;
		
		arr.clear();
		arr.resize(n);
		
		for(int i = 0; i < n; i++) scanf("%i", &arr[i]);
		
		long long c = 0, cc = 0, t = 15;
		while(t--) {
			cc = c;
			
			for(int i = 0; i < n - 1; i++)
				if(arr[i] != i + 1) {
					c += (abs(arr[i] - arr[arr[i] - 1]) * 2 - 1);
					int tmp = arr[i];
					arr[i] = arr[arr[i] - 1];
					arr[tmp - 1] = tmp;
				}
				
			if(cc != c) cc = c;
			else break;
		}
		
		if(c % 2 == 0)
			printf("Carlos\n");
		else
			printf("Marcelo\n");
	}

	return 0;
}
