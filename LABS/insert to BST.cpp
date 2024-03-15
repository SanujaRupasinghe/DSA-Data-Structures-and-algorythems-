//insert in BST
Node * insert(Node * root, int data) {
    // if the tree is empty, return a new node
    if (root == NULL) {
        return new Node(data);
    }
    // otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}