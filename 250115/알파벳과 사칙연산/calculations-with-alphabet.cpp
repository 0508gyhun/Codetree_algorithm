#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s;
// a b c d e f  = 6개

int mx = INT_MIN;
vector<int> real_num;
vector<int> v;
vector<char> c_v;
int cal()
{
  //ex} V = 1 2 3 1 1 1
  //          a b c d e f
    // int res = s[0]-'a';
    // int sum = v[res];
     int ans = 0;
     real_num.clear();
    // int len = s.size()/2;
    for(int i = 0 ; i < s.size(); i ++)
    {
        
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            int n = s[i]-'a';
            ans = v[n];
            real_num.push_back(ans);
        }
    }
    int sum = real_num[0];

    int idx = 1;
    for(int i = 0; i < c_v.size() ; i++)
    {
        int c = c_v[i];
        int num = real_num[idx++];
        if(c == '-')
        {
            sum = sum-num;
        }
        else if(c == '+')
        {
            sum = sum+ num;
        }
        else if( c == '*')
        {
            sum = sum*num;
        }
    }
    return sum;

   
}

void sol(int num)
{

    if(num == 6)
    {
        int ans = cal();
        mx = max(mx,ans);
        return ;
    }

    for(int i = 1 ; i <= 4; i++)
    {
        v.push_back(i);
        sol(num+1);
        v.pop_back();
    }
}
int main() {
    cin >> s;
    
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '-' || s[i] == '*' || s[i] == '+') c_v.push_back(s[i]);
        
            
    }
    // Write your code here!
    // for(int i : real_num) cout<< i<<" ";
   sol(0);

    cout << mx;
    return 0;
}
