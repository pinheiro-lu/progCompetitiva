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
	if (root->key > key) return search(root->l, key);
	if (root->key < key) return search(root->r, key);
	return true;
}
