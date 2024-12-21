#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[21];
string s;

int closest(string s)
{
    // cout <<"s" << s<< endl;
    int prev = -1;
    vector <int> v;
    int cnt = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] =='1')
        {
            if(prev>=0)
            {
                cnt++;
                v.push_back(i-prev);
                prev = i;
            }
            else
            {
                prev = i;
            }
        }

    }
    int mn = INT_MAX;
    // cout <<"cnt"<< cnt<< endl;
    for(int i : v)
    {
        mn = min(mn,i);
    }
    
    return mn;
}


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    cin >> s;
    int mx = INT_MIN;
    for(int i = 0 ; i <n ; i++ )
    {
        if(s[i] == '1')continue;
        s[i] ='1';
        int res = closest(s);
        mx = max(mx,res);
        s[i] = '0';
    }
    cout << mx;
    return 0;
}