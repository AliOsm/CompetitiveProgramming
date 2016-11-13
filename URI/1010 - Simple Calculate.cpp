#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double a, b, total = 0;

	cin >> a >> a >> b;
	total += (a * b);

	cin >> a >> a >> b;
	total += (a * b);

	cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << total << endl;

	return 0;
}
