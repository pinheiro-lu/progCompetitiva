#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool space;

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

void infix(Node *root) {
	if(!root) return;
	infix(root->l);
	if (space) cout << ' ';
	cout << root->key;
	space = true;
	infix(root->r);
}
void prefix(Node *root) {
	if(!root) return;
	if (space) cout << ' ';
	cout << root->key;
	space = true;
	prefix(root->l);
	prefix(root->r);
}
void postfix(Node *root) {
	if(!root) return;
	postfix(root->l);
	postfix(root->r);
	if (space) cout << ' ';
	cout << root->key;
	space = true;
}

bool search(Node *root, char key){
	if (!root) return false;
	if (root->key > key) return search(root->l, key);
	if (root->key < key) return search(root->r, key);
	return true;
}

void solve() {
	string in;
	Node *root = NULL;
	while(cin >> in) {
		space = false;
		if (in == "I") {
			char n;
			cin >> n;
			cerr << "root " << root <<  '\n';
			root = insert(root, n);
			cerr << "root " << root << " key " << root->key << '\n';
		} else if (in == "INFIXA") {
			infix(root);
			cout << '\n';
		} else if (in == "PREFIXA") {
			prefix(root);
			cout << '\n';
		} else if (in == "POSFIXA") {
			postfix(root);
			cout << '\n';
		} else {
			char n;
			cin >> n;
			cout << n << ' ' << (search(root, n) ? "" : "nao ") << "existe\n";
		}
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
