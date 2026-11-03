#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class MaxHeap {
    vector<int> h;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[p] >= h[i]) break;
            swap(h[p], h[i]);
            i = p;
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, largest = i;
            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;
            if (largest == i) break;
            swap(h[i], h[largest]);
            i = largest;
        }
    }

public:
    void insert(int priority) {
        h.push_back(priority);
        heapifyUp(h.size() - 1);
    }

    int extractMax() {
        if (h.empty()) { cout << "Heap empty\n"; return -1; }
        int mx = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) heapifyDown(0);
        return mx;
    }

    void display() const {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap mh;
    int vals[] = {40, 15, 30, 50, 10, 60};
    for (int v : vals) mh.insert(v);

    cout << "Heap: "; mh.display();
    cout << "Treated first (highest priority): " << mh.extractMax() << endl;
    cout << "Updated heap: "; mh.display();
    return 0;
}
