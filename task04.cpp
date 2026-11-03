#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char v) : data(v), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* n) { return !n->left && !n->right; }

void preorder(Node* r)  { if (!r) return; cout << r->data << " "; preorder(r->left); preorder(r->right); }
void postorder(Node* r) { if (!r) return; postorder(r->left); postorder(r->right); cout << r->data << " "; }

void inorder(Node* r) {
    if (!r) return;
    if (isLeaf(r)) { cout << r->data; return; }
    cout << "(";
    inorder(r->left);
    cout << " " << r->data << " ";
    inorder(r->right);
    cout << ")";
}

void destroy(Node* r) { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

int main() {
    Node* root = new Node('*');
    root->left = new Node('+');
    root->right = new Node('-');
    root->left->left = new Node('A');
    root->left->right = new Node('B');
    root->right->left = new Node('C');
    root->right->right = new Node('D');

    cout << "Preorder (prefix):   "; preorder(root);  cout << endl;
    cout << "Inorder (infix):     "; inorder(root);   cout << endl;
    cout << "Postorder (postfix): "; postorder(root); cout << endl;
    destroy(root);
    return 0;
}
