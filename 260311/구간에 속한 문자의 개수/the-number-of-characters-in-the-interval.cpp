#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char grid[1004][1004];
int arr[1004][1004];
int psum[4][1004][1004];

void getSum(int r1, int c1, int r2, int c2)
{
    for(int i = 1 ; i <= 3 ; i++)
    {
        cout << psum[i][r2][c2] - psum[i][r1-1][c2] - psum[i][r2][c1-1] + psum[i][r1-1][c1-1]<< " ";
        
    }
    cout << endl;
    
}
int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'a')
            {
                arr[i][j] = 1;
            }
            else if( grid[i][j] == 'b')
            {
                arr[i][j] = 2;
            }
            else {
                arr[i][j] = 3;
            }
        }
    }
// psum 만들기
    for(int k = 1 ; k <= 3 ; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                int additional =  0;
                if(arr[i][j] == k) additional = 1;

                psum[k][i][j] = psum[k][i-1][j] + psum[k][i][j-1] - psum[k][i-1][j-1] + additional;
            }    
        }
    }


    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;


        getSum(r1,c1,r2,c2);
    }

    // Please write your code here.

    return 0;
}
