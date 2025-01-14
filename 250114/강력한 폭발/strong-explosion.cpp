#include <iostream>
#include <bits/stdc++.h>


using namespace std;


vector<int> v;
vector<pair<int,int>> bomb_location;
int n;
int a[20][20];
int bomb_cnt;
int temp[20][20];

int mx = INT_MIN;

int letsbomb()
{
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[i][j];
            }
        }
        
    for(int i = 0 ; i < bomb_cnt ; i++)
    {

        
            
        int row = bomb_location[i].first;
        int col = bomb_location[i].second;

        int num = v[i];

        if(num == 1)
        {
            if(row-2 >=0)
            {
                a[row-2][col] = 1;

            } 
            if(row-1 >= 0)
            {
                a[row-1][col] = 1;
            }
            if(row+1 < n)
            {
                a[row+1][col]=1;
            }
            if(row+2 < n)
            {
                a[row+2][col] = 1;   
            }
        }
        else if ( num ==2)
        {
            if(row-1 >= 0)
            {
                a[row-1][col] = 1;
            }
            if(row+1 < n)
            {
                a[row+1][col]=1;
            }
            if(col-1 >= 0)
            {
                a[row][col-1] = 1;   
            }
            if(col+1 < n)
            {
                a[row][col+1] = 1;   
            }
        }
        else if( num ==3)
        {
            if(row-1 >= 0 && col-1 >=0)
            {
                a[row-1][col-1] = 1;
            }
            if(row+1 < n && col-1 >=0)
            {
                a[row+1][col-1]=1;
            }
            if(row+1<n && col+1<n )
            {
                a[row+1][col+1] = 1;   
            }
            if(col+1 < n && row-1 >= n)
            {
                a[row+1][col-1] = 1;   
            }
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j  = 0 ; j < n ; j++)
        {
            if(a[i][j] == 1) cnt++;
        }
    }
    return cnt;
}


void choose(int num)
{
    if(num == bomb_cnt+1)
    {
        int ans = letsbomb();
        mx = max(mx,ans);
        return;
    }

    for(int i = 1 ; i <= 3 ; i++)
    {
        v.push_back(i);
        choose(num+1);
        v.pop_back();
    }

}




int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            temp[i][j] = a[i][j];
            if(a[i][j] == 1)
            {
                bomb_location.push_back({i,j});
                bomb_cnt++;
            }
        }
    }

    choose(1);
    cout << mx;

    // Write your code here!

    return 0;
}
