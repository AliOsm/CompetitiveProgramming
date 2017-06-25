#include <stdio.h>
#include <algorithm>

typedef long long ll;

using namespace std;

int n, mx;
char s[201];

struct trie {
	int prefixes;
	trie *next[2];

	trie() {
		prefixes = 0;
		next[0] = next[1] = NULL;
	}
};

trie *root;

void insert() {
	trie *cursor = root;

	for(int i = 0; s[i] != '\0'; ++i) {
		int number = s[i] - '0';

		if(cursor->next[number] == NULL)
			cursor->next[number] = new trie;

		cursor = cursor->next[number];

		cursor->prefixes++;

		mx = max(mx, cursor->prefixes * (i + 1));
	}
}

void freeTrie(trie* cursor) {
	if(cursor == NULL)
		return;

	freeTrie(cursor->next[0]);
	freeTrie(cursor->next[1]);

	delete[] cursor;
}

int main() {
	int t;
	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d", &n);

		root = new trie;
		mx = 0;

		while(n-- != 0) {
			scanf("%s", s);
			insert();
		}

		freeTrie(root);

		printf("%d\n", mx);
	}

	return 0;
}

