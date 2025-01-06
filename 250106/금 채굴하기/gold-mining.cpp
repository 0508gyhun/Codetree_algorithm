#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[21][21];

int coinCount(int row, int col, int k)
{
    //중심이 row,col 이란 소리고 , k 일때 동전 갯수

    int sum = 0;

    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if( abs(row-i) + abs(col-j) <= k )
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }
    int mxg = 0;
    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            for(int k = 0 ; k <= 2*(n-1) ; k++)
            {
                int num_coin = coinCount(i,j,k);

                if((num_coin * m) >= (k*k + (k+1) * (k+1)) )
                {
                    mxg = max(mxg,num_coin);
                }
            }
        }
    }
    cout << mxg;

    return 0;
}