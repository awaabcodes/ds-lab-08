#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* build(const string& position) {
    int val;
    cout << "Enter value for " << position << " (-1 for none): ";
    if (!(cin >> val)) return nullptr;
    if (val == -1) return nullptr;

    Node* n = new Node(val);
    n->left  = build("left child of "  + to_string(val));
    n->right = build("right child of " + to_string(val));
    return n;
}

void preorder(Node* r)  { if (!r) return; cout << r->data << " "; preorder(r->left); preorder(r->right); }
void inorder(Node* r)   { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }
void postorder(Node* r) { if (!r) return; postorder(r->left); postorder(r->right); cout << r->data << " "; }
void destroy(Node* r)   { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

int main() {
    Node* root = build("root");

    if (!root) {
        cout << "Tree is empty." << endl;
        return 0;
    }

    cout << "\nPreorder:  "; preorder(root);  cout << endl;
    cout << "Inorder:   "; inorder(root);   cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;
    destroy(root);
    return 0;
}
