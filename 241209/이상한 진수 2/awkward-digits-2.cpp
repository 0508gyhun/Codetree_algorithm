#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s;
int n ; 

int twoToten(string s)
{
    int sum = 0 ;
    int cnt = 0 ;
    for(int i =s.size()-1 ; i >= 0 ; i--)
    {
        
        int tmp =((s[i] - '0') * pow(2,cnt));
        cnt ++;
        sum+=tmp;
    }
    return sum;
}

string toggle(string s, int i)
{
    if(s[i] == '0') s[i] = '1';
    else s[i] = '0';
    return s;
}

int main() {
   
    cin >> s;
    int ans = 0 ;
    
   // cout << twoToten(s);
    int mx = INT_MIN;
    for(int i = 0 ; i < s.size() ; i ++)
    {
        string sub = (toggle(s,i));
        int tmp = twoToten(sub);
        mx = max(mx,tmp);
        
    }
    cout << mx;





   
    // 여기에 코드를 작성해주세요.
    return 0;
}