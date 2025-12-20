#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // memset 사용

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int y, int x) {
    return (y >= 0 && x >= 0 && y < n && x < n);
}

// lo ~ hi 사이의 숫자만 밟고 지나갈 수 있는지 확인하는 BFS
bool canGo(int lo, int hi) {
    // 시작점이 범위 밖이면 시작조차 불가
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
                // 범위 내의 숫자만 이동 가능
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // [전략 변경]
    // 답(diff)을 0부터 차례대로 늘려가며 가능한지 확인한다.
    // 가장 먼저 성공하는 diff가 무조건 '최소 차이'가 된다.
    for (int diff = 0; diff <= 100; diff++) {
        
        // 현재 diff(차이)를 만들 수 있는 모든 lo(시작값)에 대해 시도
        // 숫자는 1~100 사이이므로 lo는 1부터 100까지 가능
        for (int lo = 1; lo <= 100; lo++) {
            int hi = lo + diff;
            
            // hi가 100을 넘어가면 숫자가 없으므로 의미 없음 (범위 초과)
            if (hi > 100) break;

            // BFS 수행
            if (canGo(lo, hi)) {
                cout << diff; // 찾았다! 이게 최솟값이다.
                return 0;     // 바로 종료 (더 검사할 필요 없음)
            }
        }
    }

    return 0;
}