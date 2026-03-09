#include <iostream>

using namespace std;

int N, Q;
int points[1000004];
int A[1000004], B[1000004];
int arr[1000004];
int max_n = 0;
int psum[100004];
int main() {
    cin >> N >> Q;
    fill(arr,arr+1000004,1);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
        arr[points[i]] = 0;
        max_n = max(max_n, points[i]);
    }

    for(int i = 0 ; i <= max_n ; i ++)
    {
        // cout << arr[i]<<" ";
    }
    // cout << endl;
    psum[0] = 0;
    for(int i = 1 ; i <= max_n ; i ++)
    {
        psum[i] = psum[i-1]+arr[i];
    }

    for(int i = 0 ; i <= max_n ; i ++)
    {
        // cout << psum[i]<<" ";
    }

    for (int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];
        if(A[i] < max_n)
        {
            int temp = B[i]- A[i] +1 - (psum[B[i]] - psum[A[i]-1]);
            cout << temp << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        
    }

    // Please write your code here.

    return 0;
}
