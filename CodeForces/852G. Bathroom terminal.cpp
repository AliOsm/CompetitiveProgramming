#include <bits/stdc++.h>

using namespace std;

int n, q, len, sol;
char s[101];
bool vis[100001];

struct trie {
	trie *nxt[5];
	int freq, id;
	trie() {
		for(int i = 0; i < 5; ++i)
			nxt[i] = NULL;
		freq = 0;
		id = -1;
	}
};

trie *root;

void insert(int id) {
	trie *cur = root;

	for(int i = 0, num; i < len; ++i) {
		num = s[i] - 'a';

		if(cur->nxt[num] == NULL)
			cur->nxt[num] = new trie();

		cur = cur->nxt[num];
	}

	++cur->freq;
	cur->id = id;
}

void count(trie *cur, int at) {
	if(cur == NULL || vis[cur->id])
		return;

	if(at == len) {
		if(cur->id != -1) {
			sol += cur->freq;
			vis[cur->id] = true;
		}
		return;
	}

	if(s[at] != '?')
		count(cur->nxt[s[at] - 'a'], at + 1);
	else {
		for(int i = 0; i < 5; ++i)
			count(cur->nxt[i], at + 1);
		count(cur, at + 1);
	}
}

int main() {
	root = new trie();

	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		len = strlen(s);
		insert(i);
	}

	for(int i = 0; i < q; ++i) {
		scanf("%s", s);
		len = strlen(s);
		sol = 0;
		memset(vis, false, sizeof vis);
		count(root, 0);
		printf("%d\n", sol);
	}

	return 0;
}

