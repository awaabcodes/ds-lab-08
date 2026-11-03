#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* r) {
    if (!r) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void destroy(Node* r) { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

int main() {
    Node* root = new Node(15);
    root->left = new Node(8);
    root->right = new Node(25);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->right->right = new Node(30);

    cout << "Folders (Preorder): ";
    preorder(root);
    cout << endl;
    destroy(root);
    return 0;
}
