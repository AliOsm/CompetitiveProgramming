#include <iostream>
#include <string>

using namespace std;

int main() {
	string word1;
	cin >> word1;

	word1[0] = toupper(word1[0]);

	cout << word1 << endl;

	return 0;
}
