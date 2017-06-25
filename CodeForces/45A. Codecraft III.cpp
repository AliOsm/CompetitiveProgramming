#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main() {
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	string month;
	int n, m;
	cin >> month >> n;

	for(int i = 0; i < 12; ++i)
		if(months[i] == month) {
			m = i;
			break;
		}

	cout << months[(m + n) % 12] << endl;

	return 0;
}

