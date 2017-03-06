#include <iostream>
#include <string>

using namespace std;

int main() {
	short s_len, cur_len = 0, max_len = 0, in_par_count = 0, i = 0;
	string s;
	cin >> s_len >> s;

	s_len--;

	while (i <= s_len) {
		cur_len = 0;
		
		if (s[i] == '_') {
			max_len < cur_len ? max_len = cur_len : NULL;
			i++;
		}
		else if (s[i] == '(') {
			i++;
			while (s[i] != ')')
				if (s[i] != '_') {
					while (s[i] != '_' && s[i] != ')' && i <= s_len)
						i++;
					
					in_par_count++;
				} else
					i++;
			i++;
		}
		else {
			while (s[i] != '_' && s[i] != '(' && i <= s_len) {
				cur_len++;
				i++;
			}

			max_len < cur_len ? max_len = cur_len : NULL;
		}
	}

	cout << max_len << ' ' << in_par_count << endl;
}
