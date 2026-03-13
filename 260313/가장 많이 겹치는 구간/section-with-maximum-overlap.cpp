#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int x1[200004], x2[200004];
int arr[100004];
int mx = INT_MIN;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];

        arr[x1[i]]++;
        arr[x2[i]]--;

        mx = max(mx,x2[i]);
    }
    int mxx = INT_MIN;
    
    // for(int i = 1 ; i <= mx; i++)
    // {   
    //     cout << arr[i]<< " ";
    // }
    // cout << endl;
    for(int i = 1 ; i <= mx; i++)
    {   
        int sum = 0;
        for(int j = 1 ; j <= i ;j++)
        {   
            sum+=arr[j];
        }
        mxx = max(mxx,sum);
    }
    cout << mxx;


    // Please write your code here.

    return 0;
}
