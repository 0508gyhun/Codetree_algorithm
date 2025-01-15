#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int nums[12];
vector<int> v;
int arr[5][101];
int p[5];
int mx = INT_MIN;
void init()
{
    for(int i = 1 ; i<= k ; i++)
    {
        for(int j = 1 ; j <101 ; j++)
        {
            arr[i][j] = 0;
        }
    }


    arr[1][1] = 1;
    arr[2][1] = 1;
    arr[3][1] = 1;
    arr[4][1] = 1; 
}

int cal()
{
    int cnt = 0;
    for(int i = 0 ; i <k ; i++)
    {
        if( p[i] >= m ) cnt++; 
    }
    return cnt;
}


void sol(int currnum)
{
    int ans = cal();
    mx = max(mx,ans);
    
    if(currnum == n)
    {
        return;
    }

    for(int i = 0; i < k ; i++)
    {
        p[i] += nums[currnum];
        sol(currnum+1);
        p[i] -= nums[currnum];
    }
}


int main() {
    cin >> n >> m >> k;

//n 번 턴
// m 개의 판
// k개의 말
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i = 0 ; i < k ; i++)
    {
        p[i] = 1;
    }
    sol(0);
    // Write your code here!
    cout << mx;

    return 0;
}
