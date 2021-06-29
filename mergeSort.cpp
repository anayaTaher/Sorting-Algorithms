// Taher Anaya, 11819939
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void mergeFun(int arr[], int l, int m, int r) {

    int n1 = m - l + 1;
    int n2 = r - m;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    for (int i = 0; i < n1; ++i)
        arr1[i] = arr[i + l];
    for (int i = 0; i < n2; ++i)
        arr2[i] = arr[i + m + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        arr1[i] <= arr2[j] ? arr[k++] = arr1[i++] : arr[k++] = arr2[j++];
    while (i < n1)
        arr[k++] = arr1[i++];
    while (j < n2)
        arr[k++] = arr2[j++];

}

void mergeSort(int arr[], int l, int r) {

    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    mergeFun(arr, l, m, r);

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

    mergeSort(arr, 0, n - 1);
    printArr(arr, n);

}
