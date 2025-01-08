#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int encode(string s)
{
    stack<char> stk;
    stack<int> cnt_stk;
    int cnt= 0;
    char prev = 'A';
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(stk.empty())
        {
            stk.push(s[i]);
            cnt++;
        }
        else if(stk.top() != s[i])
        {
            stk.push(s[i]);
            cnt_stk.push(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    if(cnt > 0) {
        cnt_stk.push(cnt);
    }
  string ans = "";
while(!cnt_stk.empty() && !stk.empty()) {
    ans = stk.top() + to_string(cnt_stk.top()) + ans;  // 순서 변경 및 앞에 추가
    stk.pop();
    cnt_stk.pop();
}
    

    return ans.size();
    
}

string shift(string s)
{
    //오른쪽 shift
    int size = s.size();
    char c = s[size-1];
    for(int i = size-1 ; i > 0 ; i--)
    {
        s[i] = s[i-1];
    }
    s[0] = c;
    //cout << s<< endl;
    return s;
}

string s;
int main() {
    // Please write your code here.
   
    cin >> s;
    int t = s.size();

    int mn = INT_MAX;

    // s = shift(s);
    // cout << encode(s);
    while(t--)
    {
        s = shift(s);
        mn = min (mn, encode(s));

        //문자열 길이 확인
        // 오른쪽으로 이동
    }
    cout << mn ;
    return 0;
}