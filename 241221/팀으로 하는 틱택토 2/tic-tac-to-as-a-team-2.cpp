#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n =3;
int a[3][3];

int main() {

    for(int i = 0 ; i < n ; i++)
    {
        string s;
        cin >>s;
        for(int j = 0 ; j < n ; j++)
        {
            a[i][j] = s[j]-'0';
        }
    }
    int cnt = 0;

    for(int i = 1 ; i < 10 ; i++)
    {
        bool win = false;
        for(int j = i+1 ; j < 10 ; j ++)
        {
            win = false;
            int cnti = 0 ;
            int cntj = 0;
            for(int k = 0 ; k < 3 ; k++)
            {
                cnti = 0;
                cntj = 0;
                for(int p = 0 ; p < 3 ; p++)
                {
                    if(a[k][p] == i) cnti++;
                    if(a[k][p] == j) cntj++; 
                }
                if( cnti + cntj == 3 && cnti>=1 && cntj>=1) win = true;
            }

            for(int k = 0 ; k < 3 ; k++)
            {
                cnti = 0;
                cntj = 0;
                for(int p = 0 ; p < 3 ; p++)
                {
                    if(a[p][k] == i) cnti++;
                    if(a[p][k] == j) cntj++;
                }
                if(cnti+cntj ==3 && cnti>=1 && cntj>=1) win = true;
            }
            cnti = 0 ;
            cntj = 0;

            if(a[0][0] == i) cnti++;
            if(a[1][1] == i) cnti++;
            if(a[2][2] == i) cnti++;

            if(a[0][0] == j) cntj++;
            if(a[1][1] == j) cntj++;
            if(a[2][2] == j) cntj++;

            if(cnti+cntj ==3 && cnti>=1 && cntj>=1) win = true;

            cnti = 0 ;
            cntj = 0;

            if(a[0][2] == i) cnti++;
            if(a[1][1] == i) cnti++;
            if(a[2][0] == i) cnti++;

            if(a[0][2] == j) cntj++;
            if(a[1][1] == j) cntj++;
            if(a[2][0] == j) cntj++;

            if(cnti+cntj ==3 && cnti>=1 && cntj>=1) win = true;

            if(win) cnt++;
        }
        
    }
    
    cout << cnt;
    return 0;
}