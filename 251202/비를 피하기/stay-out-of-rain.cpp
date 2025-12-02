#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, h, m;
int grid[100][100];
vector<pair<int,int>> person;
int visited[104][104];
int dist[104][104];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue<pair<int,int>> q;
int temp[104][104];

void visited_clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}
void dist_clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = 0;
        }
    }
}
bool inRange(int y,int x) {
    return (0 <= y && 0 <= x && n >y && n > x) ;
}
void bfs()
{
    while(q.size()) {
        int y,x;
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(visited[ny][nx] == 0 && grid[ny][nx] != 1&& inRange(ny,nx))
            {

                visited[ny][nx] = 1;
                q.push({ny,nx});
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
}
void prt_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] <<" ";
        }
        cout << endl;
    } 
    cout << endl;
}
void q_clear() {
    while(q.size()) {
        q.pop();
    }
}
int check() {
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 3 && dist[i][j] != 0)
            {
                ans = min(ans,dist[i][j]);
            }
        }
    } 

    if(ans == INT_MAX) return -1;
    return ans;
}
int main() {
    cin >> n >> h >> m;// 격자 사람2 천막3

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2)person.push_back({i,j});
        }
    }

    for(auto p : person)
    {
        int y = p.first;
        int x = p.second;

        visited_clear();
        dist_clear();
        q_clear();

        visited[y][x] = 1;
        dist[y][x] = 0;
        q.push({y,x});

        bfs();
        // prt_dist();
        temp[y][x] = check();
        //grid가 3인 인덱스 중, 가장 작은 dist[y][x] ,  
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << temp[i][j]<<" ";
    // Please write your code here.
        }
        cout << endl;
    }

    return 0;
}
