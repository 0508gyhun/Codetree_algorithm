#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n ; 
int x1[100];
int x2[100];
int check[2000];

int main() {

    cin >> n ;
    int cur = 0 ;
    for(int i = 0 ; i < n ; i ++)
    {
        int num;
        char dir;

        cin >> num>> dir;

        if(dir == 'L')
        {
            x1[i] = cur-num; //출발
            x2[i] = cur; //도착
            cur = cur- num;
        }
        else if( dir == 'R'){
            x1[i] = cur;
            x2[i] = cur+num;
            cur= cur+num;
        }

        x1[i] += 1000;
        x2[i] += 1000;
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = x1[i] ; j < x2[i] ; j++)
        {
            check[j]++;
        }
    }

    int cnt = 0 ;
    for(int i = 0 ; i < 2000 ; i++)
    {
        if(check[i] > 1) cnt++;
    }
    cout << cnt;

    return 0;
}
