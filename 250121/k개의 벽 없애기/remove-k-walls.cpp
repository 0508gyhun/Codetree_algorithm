#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100][100];
int dist[100][100];
int visited[100][100];
int temp[100][100];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};


queue<pair<int,int>> q;
vector<int> v;
vector<pair<int,int>> wall;

int r1, c1, r2, c2;
int totalwall;
int mn = INT_MAX;

void inita()
{
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++)
       {
            a[i][j] = temp[i][j];
        }
    }
}
void printa()
{
    cout <<"printa"<< endl;
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++)
       {
            cout << a[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}


void initvisited()
{
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++)
       {
            visited[i][j] = 0;
        }
    }
}

void initdist()
{
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++)
       {
            dist[i][j] = 0;
        }
    }
}


void bfs()
{
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx <0 || nx>=n || ny>= n || visited[ny][nx] ==1 || a[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            dist[ny][nx] = dist[y][x]+1;
            q.push({ny,nx});

        }
    }
}
void print()
{
    inita();
    initdist();
    initvisited();
    for(int i : v)
    {
        int r = wall[i].first;
        int c = wall[i].second;
        a[r][c] = 0; //벽 해제 

        //v에 들어있는 인덱스의 벽을 제외하고 bfs ㄱㄱ 
    }
   // printa();
    visited[r1][c1] = 1;
    q.push({r1,c1});
    dist[r1][c1] = 0;
    bfs();
    if(visited[r2][c2] == 1)
    {
        mn = min(mn, dist[r2][c2]);
    }
}

void sol(int idx, int cnt) // 제거할 벽 인덱스 구하기.
{
    if(cnt == k)
    {
        print();
        return;
    }
    if(idx == totalwall)
    {

        return ;
    }

    v.push_back(idx);
    sol(idx+1,cnt+1);
    v.pop_back();

    sol(idx+1,cnt);

}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            temp[i][j] = a[i][j];
            if(a[i][j] == 1) wall.push_back({i,j});
        }
    }
    totalwall = wall.size();

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    sol(0,0);

    if(mn == INT_MAX) cout << -1;
    else cout << mn;
    // Write your code here!

    return 0;
}
