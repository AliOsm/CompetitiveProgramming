#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

struct node {
	node *left, *right;
	char value;
	static node *sentinel;

	node() {
		memset(this, 0, sizeof *this);
	}

	node(char value) {
		left = right = sentinel;
		this->value = value;
	}
};

node *node::sentinel = new node;

vector<char> trav;

node * insert(node *cur, char &value) {
	if(cur == node::sentinel) return new node(value);
	if(cur->value == value) return cur;
	cur->value > value ? cur->left = insert(cur->left, value) : cur->right = insert(cur->right, value);
	return cur;
}

bool search(node *cur, char value) {
	if(cur == node::sentinel) return false;
	if(cur->value == value) return true;
	return cur->value > value ? search(cur->left, value) : search(cur->right, value);
}

void pre_order(node *cur) {
	if(cur == node::sentinel) return;
	trav.push_back(cur->value);
	pre_order(cur->left);
	pre_order(cur->right);
}

void in_order(node *cur) {
	if(cur == node::sentinel) return;
	in_order(cur->left);
	trav.push_back(cur->value);
	in_order(cur->right);
}

void post_order(node *cur) {
	if(cur == node::sentinel) return;
	post_order(cur->left);
	post_order(cur->right);
	trav.push_back(cur->value);
}

void print() {
	for(int i = 0; i < (int)trav.size(); ++i)
		cout << (i ? " " : "") << trav[i];
	cout << endl;
}

void free_bst(node *cur) {
	if(cur == node::sentinel)
		return;

	free_bst(cur->left);
	free_bst(cur->right);

	delete cur;
}

int main() {
	node *root = NULL;

	string s;
	char c;
	while(cin >> s) {
		trav.clear();

		if(s == "PREFIXA") {
			pre_order(root);
			print();
		} else if(s == "INFIXA") {
			in_order(root);
			print();
		} else if(s == "POSFIXA") {
			post_order(root);
			print();
		} else if(s == "I") {
			cin >> c;
			if(root == NULL)
				root = new node(c);
			else
				insert(root, c);
		} else {
			cin >> c;
			if(search(root, c))
				cout << c << " existe" << endl;
			else
				cout << c << " nao existe" << endl;
		}
	}

	free_bst(root);

	return 0;
}

