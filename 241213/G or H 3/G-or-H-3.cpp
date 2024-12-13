#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
int num ;
char pos;

int arr[104];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >>k;

    int mx = INT_MIN;
    for(int i = 0 ; i <  n ; i++)
    {
        cin >> num >> pos;
        if(pos == 'G')arr[num] = 1;
        else arr[num] = 2;

        mx = max(mx,num);
    }

    int mxx = INT_MIN;
    for(int i= 1 ;i <= mx-k+1; i++)
    {
        int sum = 0 ;
        for(int j = i ; j < i+k+1 ; j++)
        {
            // cout << j << " ";
            sum+=arr[j];            
        }
        // cout << endl;
        mxx = max(mxx,sum);
    }
    cout << mxx;
    return 0;
}