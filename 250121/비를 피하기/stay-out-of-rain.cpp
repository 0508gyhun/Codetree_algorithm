#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, h, m;
int a[100][100];
int visited[100][100];
int dist[100][100];
int na[100][100];

queue<pair<int,int>> q;
vector<pair<int,int>> person;
vector<pair<int,int>> safezone;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

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
void initdist()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            dist[i][j] = 0;
        }
    }
}
void printdist()
{
    cout << "print dist" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void printna()
{
    //cout << "print na" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << na[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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
            if(nx<0 || ny <0 || nx>=n || ny>=n || visited[ny][nx] ==1 || a[ny][nx] == 1)continue;
            visited[ny][nx] = 1;
            dist[ny][nx] = dist[y][x] +1;
            q.push({ny,nx}); 
        }
    }
}
int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) person.push_back({i,j});
            if(a[i][j] == 3) safezone.push_back({i,j});
        }
    }

    for(int i = 0 ; i < person.size() ; i++)
    {
        initvisited();
        initdist();
        int r = person[i].first;
        int c = person[i].second;
        // cout << "r"<<r<<" "<<"c"<<c<<endl;
        q.push({r,c});
        visited[r][c] = 1;
        dist[r][c] = 0;
        bfs();
        // printdist();
        int mn = 1000;
        for(auto zone : safezone)
        {
            int zoner = zone.first;
            int zonec = zone.second;

            if(dist[zoner][zonec] != 0)
            {
                mn = min(mn,dist[zoner][zonec]);
            }
        }
        if(mn == 1000)
        {
            na[r][c] = -1;
        }
        else
        {
            na[r][c] = mn;
        }
        

    }
    // Write your code here!
    printna();

    return 0;
}

//n h - 사람의 수  m - 피할 곳 
//0 - 이동가능 
//1 - 이동 불가
//2 - 사람
//3 - 비 피할 수 있는 곳
//사람 한명씩 dist에 거리 찍어 , 피할곳을 돌면서 최소값 출력. 없으면 -1;