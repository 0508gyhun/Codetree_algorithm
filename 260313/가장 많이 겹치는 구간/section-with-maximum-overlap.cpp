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

        for(int j = x1[i] ; j <= x2[i] ; j++)
        {
            arr[j]++;
        }

        mx = max(mx,x2[i]);
    }
    
    // for(int i = 1 ; i <= mx; i++)
    // {   
    //     cout << arr[i]<< " ";
    // }
    // cout << endl;
    int mxx = INT_MIN;
    for(int i = 1 ; i <= mx; i++)
    {   
        
        mxx = max(mxx,arr[i]);
    }
    cout << mxx;


    // Please write your code here.

    return 0;
}
