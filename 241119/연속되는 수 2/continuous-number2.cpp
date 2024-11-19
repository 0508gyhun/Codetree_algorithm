#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int n; 
int a[1004];
vector<int> v;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n ;
    int cnt = 0 ; 
    int tmp;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> tmp;
        a[i] = tmp;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(i == 0 || a[i-1] == a[i]){
            cnt++;
        }
        else{
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);

    int ans  = *max_element(v.begin(), v.end());

    cout << ans;
    // for(int i : v){
    //     cout << i <<" ";
    // }
    return 0;
}