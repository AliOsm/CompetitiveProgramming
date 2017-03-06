#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	long double p1, h1, b1;
	long double p2, h2, b2;
	long double p3, h3, b3;
	long double total = 0;

	cin >> p1;

	h1 = sqrt((p1 * p1) - ((p1 / 2.0) * (p1 / 2.0)));
	b1 = 0.5 * p1 * h1;
	h1 /= 3;
	h1 *= 2;
	h1 = sqrt((p1 * p1) - (h1 * h1));

	total += 1.0 / 3.0 * b1 * h1;

	cin >> p2;

	h2 = sqrt(((p2 / 2.0) * (p2 / 2.0)) + ((p2 / 2.0) * (p2 / 2.0)));
	h2 = sqrt((p2 * p2) - (h2 * h2));
	b2 = p2 * p2;

	total += 1.0 / 3.0 * b2 * h2;

	cin >> p3;

	h3 = p3 / 1.1755705045849462583374119092782;
	h3 = sqrt((p3 * p3) - (h3 * h3));
	b3 = 1.7204774005889669227590119773886 * (p3 * p3);

	total += 1.0 / 3.0 * b3 * h3;

	cout << setprecision(12) << fixed << total << endl;

	return 0;
}
