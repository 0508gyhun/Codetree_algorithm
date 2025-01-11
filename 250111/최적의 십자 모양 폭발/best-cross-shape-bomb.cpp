#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[50][50];
int arr_temp[50][50];
int temp_down[50][50];


void bomb(int r, int c, int k)
{
    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};

    arr[r][c] = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        int y =r;
        int x = c;
        for(int j = 1 ; j < k ; j++)
        {
            int ny = y+ dy[i];
            int nx = x + dx[i];
            if(ny< 0 || nx < 0 || ny>= n || nx >= n) continue;
            arr[ny][nx] = 0;
            y = ny;
            x = nx;
        }
    }

}

void initarr()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = arr_temp[i][j];
        }
    }
}

void print()
{
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}
void down()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp_down[i][j] = 0;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        int idx = n-1;
        for(int j = n-1 ; j >=0 ; j--)
        {
            if(arr[j][i] != 0) temp_down[idx--][i] = arr[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = temp_down[i][j];
        }
    }
}
int garocheck()
{
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ;j <n ; j++)
        {
            if(j+1>=n)continue;
            if(arr[i][j] == 0) continue;
            if(arr[i][j] == arr[i][j+1]) cnt++;
        }
    }
    return cnt;
}
int serocheck()
{
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ;j <n ; j++)
        {
            if(i+1>=n)continue;
            if(arr[i][j] == 0) continue;
            if(arr[i][j] == arr[i+1][j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr_temp[i][j] = arr[i][j];
        }
    }
    int k = n/2+1;
    // Write your code here!

    // initarr();
    // bomb(2,2,3);
    // print();
    // cout << endl;
    // down();
    // print();
    // int sum = garocheck() + serocheck();
    // cout << sum<<endl;

    int mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int p = 1 ; p <= k ; p ++)
            {
                //arr initialize
                initarr();
                bomb(i,j,p);
                // print();
                // cout << endl;
                down();
                // print();
                int sum = garocheck() + serocheck();
              //  cout << sum<<endl;
                mx = max(mx,sum);
            }
        }
    }
    cout << mx ;
    return 0;
}
