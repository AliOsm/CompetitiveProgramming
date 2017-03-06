#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct trie {
	bool is_end;
	trie* next[3];

	trie() {
		is_end = false;
		for(int i = 0; i < 3; i++)
			next[i] = NULL;
	}
};

trie* root;
string in, s;

void insert(string s) {
	trie* cursor = root;

	for(int i = 0, len = s.length(); i < len; i++) {
		int number = s[i] - 'a';

		if(cursor->next[number] == NULL) {
			cursor->next[number] = new trie;
			cursor->next[number]->is_end = false;
			for(int j = 0; j < 3; j++)
				cursor->next[number]->next[j] = NULL;
		}

		cursor = cursor->next[number];
	}

	cursor->is_end = true;
}

int find(trie* tmp, int cur, int diff) {
	int res = 0;
	
	if(diff > 1 || cur > s.length())
		return false;

	if(cur == s.length())
		return diff && tmp->is_end;
		
	int number = s[cur] - 'a';

	if(tmp->next[0] != NULL) {
		res = max(res, find(tmp->next[0], cur+1, diff + (number != 0)));
	}

	if(tmp->next[1] != NULL) {
		res = max(res, find(tmp->next[1], cur+1, diff + (number != 1)));
	}

	if(tmp->next[2] != NULL) {
		res = max(res, find(tmp->next[2], cur+1, diff + (number != 2)));
	}

	return res;
}

void freeTrie(trie* cursor) {
	if(cursor == NULL)
		return;

	for(int i = 0; i < 3; i++)
		freeTrie(cursor->next[i]);

	delete[] cursor;
}

int main() {
	root = new trie;

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> in;
		insert(in);
	}

	for(int i = 0; i < m; i++) {
		cin >> s;
		
		if(find(root, 0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	freeTrie(root);

	return 0;
}
