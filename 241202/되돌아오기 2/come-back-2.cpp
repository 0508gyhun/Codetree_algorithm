#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//.          e s w n
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
string s;
int n;
int main() {
    // 여기에 코드를 작성해주세요.


    cin >> s ;
    int dir = 3;
    
    int x = 0 ;
    int y = 0 ;

    int cnt = 0 ;
    int flag = 0;

    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == 'F')
        {
            x = x+ dx[dir];
            y = y+ dy[dir];

        }
        else if(s[i] == 'R')
        {
            dir = (dir+1)%4;
        }
        else if (s[i] == 'L')
        {
            dir = (dir-1);
            if(dir<0)
            {
                dir = dir+4;
            }
        }
        cnt++;

        if(x == 0 && y ==0){
            flag = 1;
            break;
        } 
    }

    if(flag)cout << cnt;
    else cout << -1;
    

    return 0;
}