#include <bits/stdc++.h>

using namespace std;

struct trie {
	trie *next[2];
	int cnt, num;
	trie() {
		next[0] = next[1] = NULL;
		cnt = num = 0;
	}
};

trie *root;

void insert(int x) {
	bitset<32> b(x);

	trie *cur = root;
	for(int i = 31, num; i >= 0; --i) {
		num = b[i];
		if(cur->next[num] == NULL)
			cur->next[num] = new trie();

		cur = cur->next[num];
		++cur->cnt;
	}

	cur->num = x;
}

void remove(int x) {
	bitset<32> b(x);

	trie *cur = root;
	for(int i = 31; i >= 0; --i) {
		cur = cur->next[b[i]];
		--cur->cnt;
	}
}

int find(int x) {
	bitset<32> b(x);

	trie *cur = root;
	for(int i = 31, num; cur != NULL && i >= 0; --i) {
		num = b[i];

		if(num == 0) {
			if(cur->next[1] != NULL && cur->next[1]->cnt > 0)
				cur = cur->next[1];
			else
				cur = cur->next[0];
		} else {
			if(cur->next[0] != NULL && cur->next[0]->cnt > 0)
				cur = cur->next[0];
			else
				cur = cur->next[1];
		}
	}

	if(cur == NULL)
		return x;
	return max(x ^ cur->num, x);
}

int q;

int main() {
	root = new trie();

	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		char p;
		int x;
		scanf(" %c %d", &p, &x);

		if(p == '+')
			insert(x);
		else if(p == '-')
			remove(x);
		else
			printf("%d\n", find(x));
	}

	return 0;
}

