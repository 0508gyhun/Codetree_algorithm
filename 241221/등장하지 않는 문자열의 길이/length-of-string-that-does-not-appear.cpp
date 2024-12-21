#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n;
string s;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    string s;
    cin >>s;
    // cout << s.substr(0,1)<< endl;
    // cout << s << endl;
    int mn = INT_MAX;
    for(int j = 1 ; j <n ; j ++)
        {
            string s1 = s.substr(0,j);
            //길이가 j-i+1
            int l = s.size();
            int m = s1.size();
            int cnt = 0;
            for(int p = 0 ; p <= l-m ; p++)
            {
                bool flag = true;
                for(int k = 0; k < m ; k++)
                {
                    if(s[p+k] != s1[k]) flag = false;
                }
                if(flag)cnt++;
            }
            if(cnt < 2)
            {
               // cout << s1 <<endl;
                mn = min(mn,m);
            }

        }
    cout << mn;
    return 0;
}