// Taher Anaya, 11819939
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(int arr[], int n) {

    for (int j = 1; j < n; ++j) {

        int key = arr[j];
        int i = j - 1;

        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }

}

void printArr(int arr[], int n) {

    cout << "[";
    for (int i = 0; i < n - 1; i++)
        cout << arr[i] << ",";
    cout << arr[n - 1] << "]" << endl;
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);
    printArr(arr, n);

}
