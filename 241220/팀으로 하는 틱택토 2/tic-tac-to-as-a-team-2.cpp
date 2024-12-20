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
    
    //가로
    for(int i = 0; i < 3; i++) {
        int cntsum[10] = {0,};
        for(int j = 0; j < 3; j++) {
            cntsum[a[i][j]]++;
        }
        int ans = 0;
        for(int k = 1; k < 10; k++) {
            if(cntsum[k] >= 1) ans++;
        }
        if(ans == 2) cnt++;
    }
    
    //세로
    for(int j = 0; j < 3; j++) {
        int cntsum[10] = {0,};
        for(int i = 0; i < 3; i++) {
            cntsum[a[i][j]]++;
        }
        int ans = 0;
        for(int k = 1; k < 10; k++) {
            if(cntsum[k] >= 1) ans++;
        }
        if(ans == 2) cnt++;
    }
    
    //대각선1
    {
        int cntsum[10] = {0,};
        cntsum[a[0][0]]++;
        cntsum[a[1][1]]++;
        cntsum[a[2][2]]++;
        int ans = 0;
        for(int i = 1; i < 10; i++) {
            if(cntsum[i] >= 1) ans++;
        }
        if(ans == 2) cnt++;
    }
    
    //대각선2
    {
        int cntsum[10] = {0,};
        cntsum[a[0][2]]++;
        cntsum[a[1][1]]++;
        cntsum[a[2][0]]++;
        int ans = 0;
        for(int i = 1; i < 10; i++) {
            if(cntsum[i] >= 1) ans++;
        }
        if(ans == 2) cnt++;
    }
    
    cout << cnt;
    return 0;
}