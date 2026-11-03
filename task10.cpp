#include <iostream>
using namespace std;

int swapCount = 0;

void doSwap(int& a, int& b) {
    int t = a; a = b; b = t;
    swapCount++;
}

void heapify(int arr[], int n, int i) {
    while (true) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest == i) break;
        doSwap(arr[i], arr[largest]);
        i = largest;
    }
}

void printArr(const int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {42, 17, 63, 28, 51, 9, 36, 74, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: "; printArr(arr, n);

    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    cout << "After building Max Heap: "; printArr(arr, n);

    cout << "\nExtraction steps:\n";
    for (int end = n - 1; end > 0; end--) {
        doSwap(arr[0], arr[end]);
        heapify(arr, end, 0);
        cout << "Moved " << arr[end] << " to index " << end << ": ";
        printArr(arr, n);
    }

    cout << "\nSorted array: "; printArr(arr, n);
    cout << "Total swaps: " << swapCount << endl;
    return 0;
}
