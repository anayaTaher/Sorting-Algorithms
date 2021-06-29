// Taher Anaya, 11819939
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int l, int r) {

    int k = l;

    while (true) {

        while (arr[k] <= arr[r] && r != k) r--;
        if (k == r) break;
        else {
            int temp = arr[k];
            arr[k] = arr[r];
            arr[r] = temp;
            k = r;
            l++;
        }

        while (arr[k] >= arr[l] && l != k) l++;
        if (k == l) break;
        else {
            int temp = arr[k];
            arr[k] = arr[l];
            arr[l] = temp;
            k = l;
            r--;
        }

    }

    return k;

}

void quickSort(int arr[], int l, int r) {

    if (l >= r) return;
    int k = partition(arr, l, r);
    quickSort(arr, l, k - 1);
    quickSort(arr, k + 1, r);

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

    quickSort(arr, 0, n - 1);
    printArr(arr, n);

}
