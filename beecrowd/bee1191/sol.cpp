#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string inf, pref;
struct Node {
	char key;
	Node *l = NULL;
	Node *r = NULL;

	Node(char key) : key(key){}
};

Node* insert(Node *root, char key) {
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
	cout << root->key;
	infix(root->r);
}

// preorder traversal
void prefix(Node *root) {
	if(!root) return;
	cout << root->key;
	prefix(root->l);
	prefix(root->r);
}

// postorder traversal
void postfix(Node *root) {
	if(!root) return;
	postfix(root->l);
	postfix(root->r);
	cout << root->key;
}

bool search(Node *root, char key){
	if (!root) return false;
	if (root->key == key) return true;
	return search(root->l, key) || search(root->r, key);
}

int usedInfix = 0;
Node *mega_root;
set<char> used;

Node *build(Node *root, int l, int r) {
	if (l > r) return NULL;
	int i = l, j = usedInfix, temp = usedInfix;
	while (j < pref.size() && pref.at(i) != inf.at(j)) ++j;
	root = new Node(pref.at(i));
	used.insert(pref.at(i));
	while (usedInfix < pref.size() && used.count(inf.at(usedInfix)))++usedInfix;
	//cerr << "inserting " << pref.at(i) << " i " << i << " j " << j << " ui " << usedInfix << '\n';
	root->l = build(root->l, i+1, min(r, i+j-temp));
	root->r = build(root->r, min(r, i+j-temp)+1, r);
	return root;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> pref >> inf) {
		used.clear();
		usedInfix = 0;
		mega_root = build(mega_root, 0, (int)pref.size()-1);

		//cerr << "prefix: ";
		//prefix(mega_root);
		//cerr << '\n';
		//cerr << "infix: ";
		//infix(mega_root);
		//cerr << '\n';
		postfix(mega_root);
		cout << '\n';
	}
	return 0;
}
