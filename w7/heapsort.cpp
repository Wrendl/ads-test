#include <iostream>
using namespace std;

void heapify(int arr[], int sz, int i) {

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < sz && arr[l] > arr[largest]) largest = l;

    if (r < sz && arr[r] > arr[largest]) largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, sz, largest);
    }
}

void heapSort(int arr[], int sz) {
    for (int i = sz / 2 - 1; i >= 0; i--){
        heapify(arr, sz, i);
    }

    for (int i = sz - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int sz)
{
    for (int i = 0; i < sz; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = { 7, 9, 8, 5, 6, 2 };
    int sz = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, sz);

    printArray(arr, sz);

    return 0;
}