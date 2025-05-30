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

vector<int> men(250, 400);

void fill(Node *root, int nv) {
	if (!root) return;
	cerr << "filling " << nv << '\n';
	men.at(nv) = min(men.at(nv), root->key);
	fill(root->l, nv+1);
	fill(root->r, nv+1);
}

int n;

void solve() {
	cin >> n;
	Node *root = NULL;
	while (n--) {
		int x; cin >> x;
		root = insert(root, x);
	}

	fill(root, 0);

	for (int i = 0; i < 250 && men.at(i) < 400; ++i) {
		cout << i << ' ' << men.at(i) << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
