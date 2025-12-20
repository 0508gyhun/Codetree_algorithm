#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int y, int x) {
    return (y >= 0 && x >= 0 && y < n && x < n);
}

// BFS 탐색
bool canGo(int lo, int hi) {
    if (grid[0][0] < lo || grid[0][0] > hi) return false;
    
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        int y = curr.first;
        int x = curr.second;

        if(y == n - 1 && x == n - 1) return true;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(inRange(ny, nx) && !visited[ny][nx]) {
                if(grid[ny][nx] >= lo && grid[ny][nx] <= hi) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    // 최적화를 위한 변수 (격자 내 최댓값만 알면 hi 범위를 줄일 수 있음)
    int max_val_in_grid = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            max_val_in_grid = max(max_val_in_grid, grid[i][j]);
        }
    }

    int ans = 1000;

    // [최적화 1] lo는 시작점(grid[0][0])보다 커질 수 없음.
    // lo가 시작점보다 크면 시작점을 아예 못 밟기 때문.
    for(int lo = 1; lo <= grid[0][0]; lo++) {
        
        // [최적화 2] hi는 격자 내 최댓값(max_val_in_grid)보다 클 필요 없음.
        // 더 키워봤자 갈 수 있는 길은 똑같은데 차이만 커짐.
        for(int hi = lo; hi <= max_val_in_grid; hi++) {
            
            // [최적화 3] 이미 구한 답보다 차이가 크면 검사할 필요 없음 (가지치기)
            if(hi - lo >= ans) break; 
            
            // [추가 조건] hi가 시작점보다 작으면 시작도 못함 (당연하지만 체크해주면 빠름)
            if(hi < grid[0][0]) continue;

            if(canGo(lo, hi)) {
                ans = min(ans, hi - lo);
                break; 
            }
        }
    }

    cout << ans;

    return 0;
}