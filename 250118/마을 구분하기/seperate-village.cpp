#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[25][25];
//사람1 벽0 3333ㅡ05626 7687
int visited[25][25];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int cnt;
int people_cnt;
vector<int> v;



void dfs(int y, int x)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y+ dy[i]; 
        int nx = x + dx[i];

        if(ny<0 || nx <0 || nx>=n || ny>=n || a[ny][nx] == 0 || visited[ny][nx] == 1) continue;

        visited[ny][nx] = 1;
        people_cnt++;
        dfs(ny,nx);
        
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(a[i][j] == 1 && visited[i][j] == 0)
            {
                visited[i][j] = 1;
                people_cnt=1;
                dfs(i,j);
                cnt++;
                v.push_back(people_cnt);
            }
        }
    }
    sort(v.begin(), v.end());

    cout << cnt<<endl;
    for(int i : v ) cout<<i <<endl;
    // Write your code here!

    return 0;
}
