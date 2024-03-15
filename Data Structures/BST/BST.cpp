#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
  }

  if (key < node->key) {
    node->left = insertNode(node->left, key);
  } else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }

  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }

    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}

// this fucntion take array and convert it to BST
struct node *arrayToBST(int arr[], int start, int end) {
  if (start > end) {
    return NULL;
  }

  int mid = (start + end) / 2;
  struct node *root = insertNode(NULL, arr[mid]);

  root->left = arrayToBST(arr, start, mid - 1);
  root->right = arrayToBST(arr, mid + 1, end);

  return root;
}

