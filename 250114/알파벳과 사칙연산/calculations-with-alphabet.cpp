#include <iostream>
#include <bits/stdc++.h>


using namespace std;

string s;
vector<char> c;
vector<int> v;
int cnt;
int c_cnt;
int mx = INT_MIN;

int cal()
{
    int res = v[0];
    int numcnt = 1;
    for(int i = 0 ; i < c_cnt ; i++)
    {
        if(c[i] == '+')
        {
            res = res+v[numcnt];
        }
        else if ( c[i] == '-')
        {
            res = res- v[numcnt];
        }
        else if( c[i] == '*')
        {
            res = res * v[numcnt];
        }
        numcnt++;
    }
    return res;
}



void choose(int num)
{
    if(num == cnt+1)
    {
        int ans = cal();
        mx = max(mx,ans);
        return;
    }

    for(int i = 1 ; i <= 4 ;i++)
    {
        

        v.push_back(i);
        choose(num+1);
        v.pop_back();        
    }
}


int main() {
    cin >> s;

    // Write your code here!
    for(int i= 0 ; i < s.size(); i++)
    {
        if(s[i] >='a' && s[i] <= 'z')
        {
            cnt++;   
        }// 알파벳인 경우
        else
        {
            c.push_back(s[i]);
            c_cnt++;
        }
    }


    choose(0);
    cout << mx ;
    return 0;
}
