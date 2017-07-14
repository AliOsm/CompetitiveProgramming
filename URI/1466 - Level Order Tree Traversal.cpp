#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

struct node {
	static node *sentinel;

	node *left, *right;
	int value;

	node() {
		memset(this, 0, sizeof *this);
	}

	node(int value) {
		left = right = sentinel;
		this->value = value;
	}
};

node *node::sentinel = new node;

node * insert(node *cur, int &value) {
	if(cur == node::sentinel) return new node(value);
	if(cur->value > value) cur->left = insert(cur->left, value);
	if(cur->value < value) cur->right = insert(cur->right, value);
	return cur;
}

void free_bst(node *cur) {
	if(cur == node::sentinel) return;
	free_bst(cur->left);
	free_bst(cur->right);
	delete cur;
}

int n, tmp;
queue<node*> qu;
vector<int> bfs_res;

void BFS(node *cur) {
	while(!qu.empty()) qu.pop();
	qu.push(cur);

	int size;
	node *fr;
	while(!qu.empty()) {
		size = qu.size();

		while(size-- != 0) {
			fr = qu.front();
			qu.pop();

			bfs_res.push_back(fr->value);

			if(fr->left != node::sentinel)
				qu.push(fr->left);

			if(fr->right!= node::sentinel)
				qu.push(fr->right);
		}
	}
}

int main() {
	node *root;

	int t;
	scanf("%d", &t);
	for(int cnt = 1; t-- != 0; ++cnt) {
		bfs_res.clear();
		root = NULL;

		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			if(root == NULL)
				root = new node(tmp);
			else
				insert(root, tmp);
		}

		printf("Case %d:\n", cnt);
		BFS(root);
		for(int i = 0; i < (int)bfs_res.size(); ++i)
			printf("%s%d", (i != 0 ? " " : ""), bfs_res[i]);
		puts("\n");
		free_bst(root);
	}

	return 0;
}

