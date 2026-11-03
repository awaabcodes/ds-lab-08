#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Request {
    int id;
    int priority;
    long seq;
};

bool before(const Request& a, const Request& b) {
    if (a.priority != b.priority) return a.priority < b.priority;
    return a.seq < b.seq;
}

class EmergencyQueue {
    vector<Request> h;
    long counter = 0;

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (!before(h[i], h[p])) break;
            swap(h[i], h[p]);
            i = p;
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, best = i;
            if (l < n && before(h[l], h[best])) best = l;
            if (r < n && before(h[r], h[best])) best = r;
            if (best == i) break;
            swap(h[i], h[best]);
            i = best;
        }
    }

public:
    bool empty() const { return h.empty(); }

    void insert(int id, int priority) {
        h.push_back({id, priority, counter++});
        heapifyUp(h.size() - 1);
        cout << "Inserted request " << id << " (priority " << priority << ")\n";
    }

    void removeMostUrgent() {
        if (h.empty()) { cout << "No pending requests.\n"; return; }
        Request top = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) heapifyDown(0);
        cout << "Dispatched request " << top.id << " (priority " << top.priority << ")\n";
    }

    void peek() const {
        if (h.empty()) { cout << "No pending requests.\n"; return; }
        cout << "Next most urgent: request " << h[0].id
             << " (priority " << h[0].priority << ")\n";
    }
};

int main() {
    EmergencyQueue q;
    q.insert(101, 3);
    q.insert(102, 1);
    q.insert(103, 4);
    q.insert(104, 1);
    q.insert(105, 2);
    q.insert(106, 3);

    cout << "\n";
    q.peek();
    q.removeMostUrgent();
    q.removeMostUrgent();
    q.peek();
    q.removeMostUrgent();
    q.removeMostUrgent();
    q.peek();
    q.removeMostUrgent();
    q.removeMostUrgent();
    q.removeMostUrgent();
    return 0;
}
