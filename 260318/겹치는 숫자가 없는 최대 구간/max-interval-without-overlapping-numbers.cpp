#include <iostream>

using namespace std;

int n;
int arr[100004];
int count[100004];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int j = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        while(j+1 <= n && count[arr[j+1]] != 1)
        {
            count[arr[j+1]]++;
            j++;
        }

        ans = max(ans,j-i+1);

        count[arr[i]]--;
    }

    cout << ans;

    // Please write your code here.

    return 0;
}
