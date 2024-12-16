#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cnt;
int arr[6];
int sum;

int cal (int i , int j , int k){
    int tmp = arr[i]+arr[j]+arr[k];
    int tmp2= sum - tmp;
    return abs(tmp-tmp2);
}

int main() {
    // 여기에 코드를 작성해주세요.

    for(int i = 0 ; i < 6 ; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    int mn = INT_MAX;
    for(int i = 0 ; i < 6 ; i++)
    {
        for(int j = i ; j < 6 ; j++)
        {
            for(int k = j ; k < 6 ; k++)
            {
                int res = cal(i,j,k);
                mn = min(mn,res);
            }
            
        }
    }
    cout << mn;
    return 0;
}