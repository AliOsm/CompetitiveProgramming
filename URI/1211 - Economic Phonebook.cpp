#include <iostream>
#include <string>

using namespace std;

struct trie {
	bool is_number;
	trie* next[10];

	trie() {
		is_number = false;
		for(int i = 0; i < 10; i++)
			next[i] = NULL;
	}
};

trie* root;
int res;

void insert(string s) {
	trie* cursor = root;

	for(int i = 0, len = s.length(); i < len; i++) {
		int number = s[i] - '0';

		if(cursor->next[number] == NULL) {
			cursor->next[number] = new trie;
			cursor->next[number]->is_number = false;
			for(int j = 0; j < 10; j++)
				cursor->next[number]->next[j] = NULL;
		} else {
			res++;
		}

		cursor = cursor->next[number];
	}

	cursor->is_number = true;
}

void freeTrie(trie* cursor) {
	if(cursor == NULL)
		return;

	for(int i = 0; i < 10; i++)
		freeTrie(cursor->next[i]);

	delete[] cursor;
}

int main() {
	int n;
	
	while(cin >> n) {
		res = 0;
		root = new trie;

		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;

			insert(s);
		}

		cout << res << endl;

		freeTrie(root);
	}

	return 0;
}
