#include <stdio.h>

using namespace std;

int arr[9];

int main() {
	int n;
	scanf("%i", &n);
	for (int i = 0; i < 9; i++)
	    scanf("%i", &arr[i]);

	bool f = true;
	for (int i = 0; i < 9; i++)
		if (n >= arr[i])
			f = false;

	if (f)
		puts("-1");
	else {
		int min_v = 1e9, min_n = 1e9, mx_v, mx_n;
		for (int i = 0; i < 9; i++)
			if (arr[i] <= min_v) {
				min_v = arr[i];
				min_n = i;
			}

		int digits = n / min_v;
		int esc = n % min_v;

		if (!esc) {
			for (int i = 0; i < digits; i++)
				printf("%i", min_n + 1);
			putchar('\n');
		} else {
			while (esc) {
				digits--;
				esc += arr[min_n];

				mx_v = 1e9, mx_n = 1e9;

				for (int i = 0; i < 9; i++)
					if (arr[i] <= esc) {
						mx_v = arr[i];
						mx_n = i;
					}

				if ((mx_v == 1e9 && mx_n == 1e9) || mx_n == min_n) {
					digits++;
					esc -= arr[min_n];
					break;
				}

				esc -= mx_v;
				printf("%i", mx_n + 1);
			}

			for (int i = 0; i < digits; i++)
				printf("%i", min_n + 1);
			putchar('\n');
		}
	}

	return 0;
}
