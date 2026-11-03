#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* r)  { if (!r) return; cout << r->data << " "; preorder(r->left); preorder(r->right); }
void inorder(Node* r)   { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }
void postorder(Node* r) { if (!r) return; postorder(r->left); postorder(r->right); cout << r->data << " "; }

void destroy(Node* r) { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Preorder:  "; preorder(root);  cout << endl;
    cout << "Inorder:   "; inorder(root);   cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;
    destroy(root);
    return 0;
}
