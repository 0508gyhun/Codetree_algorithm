#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100][100];
int visited[100][100];
int r[10000], c[10000];
vector<int> v;


int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

 // 0 가능 1 불가늧 
 int cnt;
 queue<pair<int,int>> q;
void bfs(int y, int x)
{
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y+ dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 ||ny>= n || nx >=n || visited[ny][nx] == 1 || a[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            cnt++;
            q.push({ny,nx});
        }
    }

    

}


int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    for (int i = 0; i < k; i++){
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
        if(visited[r[i]][c[i]] == 0)
        {
            cnt=1;
            q.push({r[i],c[i]});
            visited[r[i]][c[i]] = 1;
            bfs(r[i],c[i]);
            v.push_back(cnt);
        }
        
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++ ) 
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(visited[i][j] ==1) ans++;
        }
    }
    cout << ans ;

    // Write your code here!

    return 0;
}
