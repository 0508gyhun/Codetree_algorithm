#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10];
int x,y;

bool isInter(int it)
{
    int a[10] = {0,};
    string s = to_string(it);

    for(int i = 0 ; i < s.size() ; i++)
    {
        int tmp = s[i]-'0';
        a[tmp] =1;
    }
    int cnt = 0 ;
    for(int i= 0 ; i < 10 ; i++)
    {
        if(a[i] ==1 )cnt++;
    }
    if(cnt == 2) return true;
    else return false;

}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> x >> y;

    int cnt = 0 ;
    for(int i = x ; i <= y ; i++)
    {
        if(isInter(i)) cnt++;
    }
    cout<< cnt;
    return 0;
}