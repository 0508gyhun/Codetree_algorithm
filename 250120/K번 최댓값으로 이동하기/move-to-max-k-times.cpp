#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100][100];
int r, c;
int visited[100][100];
queue <pair<int,int>> q;

void initvisited()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            visited[i][j] = 0;
        }
    }
}

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int mx ;
pair<int,int> findrc()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(a[i][j] == mx)
            {
                pair<int,int> ans;
                ans.first = i;
                ans.second = j;
                return ans;
            }
        }
    }
}
void bfs(int rr,int cc)
{
    mx = 1;
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx <0 || ny>=n || nx >=n || visited[ny][nx] == 1 ||a[ny][nx] >= a[rr][cc] ) continue;
            if(mx < a[ny][nx])
            {
                mx = a[ny][nx];

            }
            visited[ny][nx] = 1;
            q.push({ny,nx});

        }
    }

}
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cin >> r >> c;
    r--;
    c--;

    for(int i = 0 ; i < k ; i++)
    {
        initvisited();
       // q.clear();
        q.push({r,c});
        visited[r][c]= 1;
        bfs(r,c);
        pair<int,int> result = findrc();
        if(result.first == r && result.second == c)
        {
            break;
        }
        else
        {
            r = result.first;
            c = result.second;
        }
     

        //cout << mx <<endl;
    }
    cout << r+1 <<" "<< c+1;

    // Write your code here!

    return 0;
}
