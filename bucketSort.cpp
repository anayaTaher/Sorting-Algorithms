// Taher Anaya, 11819939

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
int maxValue, minValue, maxDigits;

int partition(vector<int> &arr, int l, int r) {

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

void quickSort(vector<int> &arr, int l, int r) {

    if (l >= r) return;
    int k = partition(arr, l, r);
    quickSort(arr, l, k - 1);
    quickSort(arr, k + 1, r);

}

void runFirst() {

    int temp = maxValue, counter1 = -1, counter2 = -1;
    while (temp) {
        temp /= 10;
        counter1++;
    }
    temp = minValue;
    while (temp) {
        temp /= 10;
        counter2++;
    }
    maxDigits = counter1 >= counter2 ? counter1 : counter2;

}

void bucketSort(int arr[], int n) {

    runFirst();

    vector<int> buckets[11];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 11; ++j)
            if (arr[i] <= minValue + j * (int) pow(10, maxDigits)) {
                buckets[j].push_back(arr[i]);
                break;
            }

    for (int i = 0; i < 11; ++i)
        quickSort(buckets[i], 0, buckets[i].size() - 1);

    int index = 0;
    for (int i = 0; i < 11; ++i)
        for (int j = 0; j < (int)buckets[i].size(); ++j)
            arr[index++] = buckets[i][j];

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
    cin >> arr[0];
    maxValue = arr[0];
    minValue = arr[0];

    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] > maxValue) maxValue = arr[i];
        if (arr[i] < minValue) minValue = arr[i];
    }

    bucketSort(arr, n);

    printArr(arr, n);

    return 0;
}
