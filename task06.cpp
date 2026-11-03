#include <iostream>
using namespace std;

class CompleteBinaryTree {
    static const int MAX = 100;
    int tree[MAX];
    int count;

public:
    CompleteBinaryTree() : count(0) {}

    void insert(int val) {
        if (count == MAX) { cout << "Tree full\n"; return; }
        tree[count++] = val;
    }

    int size() const { return count; }

    void preorder(int index) {
        if (index >= count) return;
        cout << tree[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }

    void inorder(int index) {
        if (index >= count) return;
        inorder(2 * index + 1);
        cout << tree[index] << " ";
        inorder(2 * index + 2);
    }

    void postorder(int index) {
        if (index >= count) return;
        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << tree[index] << " ";
    }
};

int main() {
    CompleteBinaryTree t;
    int vals[] = {10, 20, 30, 40, 50, 60};
    for (int v : vals) t.insert(v);

    cout << "Preorder:  "; t.preorder(0);  cout << endl;
    cout << "Inorder:   "; t.inorder(0);   cout << endl;
    cout << "Postorder: "; t.postorder(0); cout << endl;
    return 0;
}
