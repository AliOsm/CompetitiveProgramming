#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

struct node {
	node *left, *right;
	char value;
	static node *sentinel;

	node() {
		memset(this, 0, sizeof *this);
	}

	node(char key) {
		left = right = sentinel;
		this->value = key;
	}
};

node *node::sentinel = new node();

void free_bst(node *cur) {
	if(cur == node::sentinel)
		return;

	free_bst(cur->left);
	free_bst(cur->right);

	delete cur;
}

void post_order(node *cur) {
	if(cur == node::sentinel)
		return;

	post_order(cur->left);
	post_order(cur->right);
	cout << cur->value;
}

string preord, inord;
node *root;

void build_bst(node *&cur, int l, int r) {
	if(l > r)
		return;

	cur = new node(preord[0]);

	int cur_in = inord.find(preord[0]);
	preord.erase(0, 1);

	build_bst(cur->left, l, cur_in - 1);
	build_bst(cur->right, cur_in + 1, r);
}

int main() {
	int t, n;
	cin >> t;
	while(t-- != 0) {
		cin >> n >> preord >> inord;
		root = NULL;

		build_bst(root, 0, preord.length() - 1);
		post_order(root);
		cout << endl;

		free_bst(root);
	}

	return 0;
}

