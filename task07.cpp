#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class MinHeap {
    vector<int> h;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[p] <= h[i]) break;
            swap(h[p], h[i]);
            i = p;
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
            if (l < n && h[l] < h[smallest]) smallest = l;
            if (r < n && h[r] < h[smallest]) smallest = r;
            if (smallest == i) break;
            swap(h[i], h[smallest]);
            i = smallest;
        }
    }

public:
    void insert(int urgency) {
        h.push_back(urgency);
        heapifyUp(h.size() - 1);
    }

    int extractMin() {
        if (h.empty()) { cout << "Heap empty\n"; return -1; }
        int mn = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) heapifyDown(0);
        return mn;
    }

    void display() const {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinHeap mh;
    int vals[] = {35, 12, 25, 8, 40, 5};
    for (int v : vals) mh.insert(v);

    cout << "Heap: "; mh.display();
    cout << "Removed smallest urgency: " << mh.extractMin() << endl;
    cout << "Updated heap: "; mh.display();
    return 0;
}
