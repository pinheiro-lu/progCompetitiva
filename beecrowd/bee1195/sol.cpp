#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
	int key;
	Node *l = NULL;
	Node *r = NULL;

	Node(int key) : key(key){}
};

Node* insert(Node *root, int key) {
	if(!root) {
		return root = new Node(key);
	}
	if (root->key < key) {
		root->r = insert(root->r, key);
	} else {
		root->l = insert(root->l, key);
	}
	return root;
}

// inorder traversal
void infix(Node *root) {
	if(!root) return;
	infix(root->l);
	cout << ' ' << root->key;
	infix(root->r);
}

// preorder traversal
void prefix(Node *root) {
	if(!root) return;
	cout << ' ' << root->key;
	prefix(root->l);
	prefix(root->r);
}

// postorder traversal
void postfix(Node *root) {
	if(!root) return;
	postfix(root->l);
	postfix(root->r);
	cout << ' ' << root->key;
}

bool search(Node *root, int key){
	if (!root) return false;
	if (root->key > key) return search(root->l, key);
	if (root->key < key) return search(root->r, key);
	return true;
}

void solve() {
	int n;
	cin >> n;
	Node *root = NULL;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		root = insert(root, x);
	}
	cout << "Pre.:";
	prefix(root);
	cout << '\n';
	cout << "In..:";
	infix(root);
	cout << '\n';
	cout << "Post:";
	postfix(root);
	cout << '\n';
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i<= t; ++i) {
		cout << "Case " << i << ":\n";
		solve();
		cout << '\n';
	}


	return 0;
}
