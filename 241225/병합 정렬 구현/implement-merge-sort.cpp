#include <iostream>
using namespace std;

int n;
int arr[100004];
int merged_arr[100004];

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            merged_arr[k] = arr[i];
            k++;
            i++;
        }
        else {
            merged_arr[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        merged_arr[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high) {
        merged_arr[k] = arr[j];
        k++;
        j++;
    }

    for (int k = low; k <= high; k++) {
        arr[k] = merged_arr[k];
    }
}

void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}