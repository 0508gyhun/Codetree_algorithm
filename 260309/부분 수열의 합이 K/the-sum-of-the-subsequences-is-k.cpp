#include <iostream>

using namespace std;

int n, k;
int arr[1005];
int psum[1005];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    psum[0] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        psum[i] = psum[i-1]+arr[i];
    }
    int cnt = 0;

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0; j < i ; j++) { 
            // 수정 3: abs() 제거
            if(psum[i] - psum[j] == k) {
                cnt++;
            }
        }
    }
    
    cout << cnt;


    // Please write your code here.

    return 0;
}
