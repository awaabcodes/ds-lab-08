#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void destroy(Node* r) { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

int main() {
    Node* root = new Node(35);
    root->left = new Node(18);
    root->right = new Node(55);
    root->left->left = new Node(10);
    root->left->right = new Node(25);
    root->right->left = new Node(45);
    root->right->right = new Node(65);

    cout << "Employee IDs (Inorder): ";
    inorder(root);
    cout << endl;
    destroy(root);
    return 0;
}
