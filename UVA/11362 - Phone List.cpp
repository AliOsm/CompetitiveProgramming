#include <stdio.h>
#include <cstddef>

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

bool insert(char s[]) {
	trie* cursor = root;

	for(int i = 0; s[i] != '\0'; i++) {
		int number = s[i] - '0';

		if(cursor->next[number] == NULL) {
			cursor->next[number] = new trie;
			cursor->next[number]->is_number = false;
			for(int j = 0; j < 10; j++)
				cursor->next[number]->next[j] = NULL;
		}

		cursor = cursor->next[number];

		if(cursor->is_number)
			return false;
	}

	for(int i = 0; i < 10; i++)
		if(cursor->next[i] != NULL)
			return false;

	cursor->is_number = true;
	return true;
}

void freeTrie(trie* cursor) {
	if(cursor == NULL)
		return;

	for(int i = 0; i < 10; i++)
		freeTrie(cursor->next[i]);

	delete[] cursor;
}

int main() {
	int t;
	scanf("%i", &t);

	while(t--) {
		bool error = false;
		root = new trie;

		int n;
		scanf("%i", &n);

		for(int i = 0; i < n; i++) {
			char s[11];
			scanf("%s", s);

			if(!insert(s))
				error = true;
		}

		if(error)
			puts("NO");
		else
			puts("YES");

		freeTrie(root);
	}

	return 0;
}
