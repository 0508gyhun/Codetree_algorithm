#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int grid[100][100];
int r, c;
pair<int,int> cur_pos;
int visited[104][104];
queue<pair<int,int>> q;
int dy[4] = {-1,0,1,0};
int dx[4]= {0,1,0,-1};

void visited_clear() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0 ;
        }
    }
}

bool inRange(int r, int c , int target_n) {
    if ( 0 <= r && r < n && 0 <= c && c < n && grid[r][c] < target_n) return true;
    return false;
}

void bfs() {
    int curx,cury;
    tie(cury,curx) = cur_pos;
    visited[cury][curx] = 1;
    q.push(cur_pos);
    int target_n = grid[cury][curx] ;

    while(!q.empty()) {
        int y,x;
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx] == 0 && inRange(ny,nx, target_n)) {
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }        
    }
}
bool NeedUpadate(pair<int,int> best_pos, pair<int,int> new_pos) {
    if(best_pos == make_pair(-1,-1)) return true;

    int bestx,besty;
    tie(besty,bestx) = best_pos;

    int newx,newy;
    tie(newy,newx) = new_pos;

    return make_tuple(grid[newy][newx], -newy, -newx) > make_tuple(grid[besty][bestx], -besty, -bestx);
}
bool move() {
    visited_clear();

    bfs();

    pair<int,int> best_pos = {-1,-1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j] == 0 || make_pair(i,j) == cur_pos) continue;

            pair<int,int> new_pos = make_pair(i,j);
            if(NeedUpadate(best_pos, new_pos)){
                best_pos = new_pos;
            }
        }
    }
    if(best_pos == make_pair(-1,-1)) return false;
    else {
        cur_pos = best_pos;
        return true;
    }
}
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    r--;
    c--;
    cur_pos = {r,c};

     
    while(k--) {

        bool ismoved = move();
        if(!ismoved) break;

    }
    cout << cur_pos.first +1 <<" "<<cur_pos.second+1;
    // Please write your code here.

    return 0;
}
