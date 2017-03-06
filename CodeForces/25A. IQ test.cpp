#include <iostream>
#include <vector>

using namespace std;

int countEven(vector<int> arr) {
	int evens = 0;
	for(int i = 0; i < arr.size(); i++)
		if(arr[i] % 2 == 0)
			evens++;
	return evens;
}

int main() {
	int t;
	cin >> t;
	vector<int> arr(t);

	for(int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	int evens = countEven(arr);

	if(evens == 1) {
		for(int i = 0; i < arr.size(); i++)
			if(arr[i] % 2 == 0)
				cout << i + 1 << endl;
	} else {
		for(int i = 0; i < arr.size(); i++)
			if(arr[i] % 2 != 0)
				cout << i + 1 << endl;
	}

	return 0;
}
