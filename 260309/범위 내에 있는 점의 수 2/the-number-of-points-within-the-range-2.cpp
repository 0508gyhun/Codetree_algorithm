#include <iostream>

using namespace std;

int N, Q;
int points[100000];
int A[100000], B[100000];
int arr[100004];
int main() {
    cin >> N >> Q;
    fill(arr,arr+100004,1);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
        arr[points[i]] = 0;
        max_n = max(max_n, points[i]);
    }

    for(int i = 0 ; i <= max_n ; i ++)
    {
        cout << arr[i]<<" ";
    }

    for (int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];
    }

    // Please write your code here.

    return 0;
}
