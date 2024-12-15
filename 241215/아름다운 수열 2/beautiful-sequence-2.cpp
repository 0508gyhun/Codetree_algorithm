#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int n,m;
int arr1[104];
int arr2[104];
int tmp[104];

int cnt;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >>m;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
	for(int i = 0; i < m; i++)
        cin >> arr2[i];
    sort(arr2,arr2+m);

    for(int i = 0 ; i <= n-m ; i++)
    {
        for(int j = 0 ; j < m; j ++)
        {
            tmp[j] = arr1[i+j];
        }
        sort(tmp , tmp+m);
        bool issame = true;
        for(int j = 0 ; j < m ; j++)
        {
            if(arr2[j] != tmp[j]){
                issame = false;
                break;
        }
        if(issame) cnt++;
    }

    cout << cnt;
    return 0;


}