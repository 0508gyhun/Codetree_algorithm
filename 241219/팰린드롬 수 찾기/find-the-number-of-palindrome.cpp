#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int x,y;

bool ispel(int i)
{
    string s = to_string(i);
    string s1 = s;
    reverse(s.begin(), s.end());
    if(s1 == s ) return true;
    return false;
}

int cnt = 0;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x>>y;

    for(int i = x ; i <= y ; i++)
    {
        if(ispel(i)) cnt++;
    }
    cout << cnt;
    return 0;
}