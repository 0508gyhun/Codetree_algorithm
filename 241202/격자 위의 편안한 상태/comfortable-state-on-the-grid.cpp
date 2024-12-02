#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int n,t;
int r,c;
int a[104][104];

bool isgood(int y, int x)
{
    int cnt = 0 ;
    if(a[r+1][c]==1)cnt++;
    if(a[r-1][c] == 1)cnt++;
    if(a[r][c-1]==1) cnt++;
    if(a[r][c+1]==1) cnt++;

    if(cnt == 3) return true;
    else return false;
}

int main() {
    // 여기에 코드를 작성해주세요.


    cin >> n >> t;

    for(int i = 0 ; i < t ; i++)
    {
        cin >> r >> c;
        r--;
        c--;
        a[r][c] =1;
        if(isgood(r,c))
        {
            cout << 1<<'\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}