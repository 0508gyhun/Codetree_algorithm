#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int n,m;
int a[202][202];

int sol1(int row, int col)
{
    int sum = 0;
    int mx = INT_MIN;
    int sum1 = (a[row][col+1] + a[row+1][col] + a[row+1][col+1]);//ㄴ 반대
    mx = max(mx,sum1);
    int sum2 = (a[row][col]+ a[row+1][col] + a[row+1][col+1]); // ㄴ
    mx = max(mx,sum2);

    int sum3 = (a[row][col] + a[row][col+1] + a[row+1][col+1]);          
    mx = max(mx,sum3);
                                               //ㄱ
    int sum4 = a[row][col] + a[row][col+1] + a[row+1][col];
    mx = max(mx,sum4);

    return mx;
    
}

int sol2(int row, int col)
{
    int sum = a[row][col]+ a[row][col+1] + a[row][col+2];
    return sum;
}
int sol3(int row, int col)
{
    int sum = a[row][col]+ a[row+1][col] + a[row+2][col];
    return sum;
}

int main() {

    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
        }
    }
 // 니은자
    int mx = INT_MIN;
     for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(i +1 >= n || j+1 >= m) continue;
            mx = max(mx,sol1(i,j));

        }
    }
//  가로
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(j+2 >= m) continue;
            mx = max(mx,sol2(i,j));

        }
    }
//가로 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(j+2 >= m) continue;
            mx = max(mx,sol2(i,j));

        }
    }

    //세로
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(i+2 >= n) continue;
            mx = max(mx,sol3(i,j));

        }
    }
    cout << mx;

    // Please write your code here.
    return 0;
}