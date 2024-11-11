#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
string s[104];
string t;
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n >> k >>t;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        bool flag = true;
        for(int j = 0 ; j < t.size() ; j++)
        {
            if(t[j] != str[j]){
                flag = false;
            }
        }
        if(flag == true)
        {
            s[cnt] = str;
            cnt++;
        }
    }
    sort(s, s + cnt);

    // for(auto si : s)
    // {
    //     cout << si << " ";
    // }
    cout << s[k-1];



    return 0;
}