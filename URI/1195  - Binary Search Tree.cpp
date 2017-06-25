#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	node *left, *right;
	int value;
	static node *sentinel;

	node() {
		memset(this, 0, sizeof *this);
	}

	node(int key) {
		left = right = sentinel;
		this->value = key;
	}
};

node *node::sentinel = new node();

node * insert(node *cur, int value) {
	if(cur == node::sentinel)
		return new node(value);

	if(cur->value == value)
		return cur;

	if(cur->value > value)
		cur->left = insert(cur->left, value);
	else
		cur->right = insert(cur->right, value);

	return cur;
}

void pre_order(node *cur) {
	if(cur == node::sentinel)
		return;

	printf(" %d", cur->value);
	pre_order(cur->left);
	pre_order(cur->right);
}

void in_order(node *cur) {
	if(cur == node::sentinel)
		return;

	in_order(cur->left);
	printf(" %d", cur->value);
	in_order(cur->right);
}

void post_order(node *cur) {
	if(cur == node::sentinel)
		return;

	post_order(cur->left);
	post_order(cur->right);
	printf(" %d", cur->value);
}

void free_bst(node *cur) {
	if(cur == node::sentinel)
		return;

	free_bst(cur->left);
	free_bst(cur->right);

	delete cur;
}

int main() {
	node *root;

	int t, n, tmp;
	scanf("%d", &t);
	for(int cnt = 1; t--; ++cnt) {
		root = NULL;

		scanf("%d", &n);
		while(n-- != 0 && scanf("%d", &tmp))
			if(root == NULL)
				root = new node(tmp);
			else
				root = insert(root, tmp);

		printf("Case %d:\n", cnt);
		printf("Pre.:");
		pre_order(root);
		puts("");
		printf("In..:");
		in_order(root);
		puts("");
		printf("Post:");
		post_order(root);
		puts("\n");

		free_bst(root);
	}

    return 0;
}

