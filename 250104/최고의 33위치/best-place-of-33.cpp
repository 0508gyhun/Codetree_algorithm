#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int N;
int grid[20][20];


int sol(int row, int col)
{
    int sum = 0;
    for(int i= row ; i < row+3 ; i ++)
    {
        for(int j = col ;j < col+3 ; j++)
        {
            sum+=grid[i][j];
        }
    }
    return sum;
}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }


    int mx = INT_MIN;
    // Write your code here!

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i+2 >= N || j+2 >= N)
            {
                continue;
            }       
            else
            {
                int res = sol(i,j);
                mx = max(mx,res);

            }
        }
    }
    cout << mx;

    return 0;
}
