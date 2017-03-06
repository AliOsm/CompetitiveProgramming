#include <iostream>

int main() {
	unsigned long long n;

	std::cin >> n;

	if (n % 2 == 0)
		std::cout << 2 << std::endl;
	else
		std::cout << 1 << std::endl;

	return 0;
}
