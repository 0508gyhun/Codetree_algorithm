#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // memset

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int y, int x) {
    return (y >= 0 && x >= 0 && y < n && x < n);
}

// lo 이상 hi 이하의 숫자만 밟을 수 있는지 확인하는 BFS
bool canGo(int lo, int hi) {
    // 이미 밖에서 범위를 잡고 들어오지만, 혹시 모르니 시작점 체크
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

    // 1. 답(차이, diff)을 0부터 하나씩 늘려가며 테스트
    // 숫자의 범위가 보통 1~100이지만, 혹시 몰라 넉넉히 돌립니다. 
    // 정답을 찾으면 바로 종료하므로 1000까지 잡아도 속도 문제 없습니다.
    for (int diff = 0; diff <= 1000; diff++) {
        
        // 2. lo(구간 최솟값) 설정
        // 핵심: lo는 절대 시작점(grid[0][0])보다 클 수 없습니다.
        // 시작점이 50인데 lo가 51이면 시작점을 못 밟기 때문입니다.
        // 따라서 lo는 1부터 시작점까지만 반복합니다.
        for (int lo = 1; lo <= grid[0][0]; lo++) {
            
            int hi = lo + diff;

            // 핵심: hi(구간 최댓값)는 절대 시작점(grid[0][0])보다 작을 수 없습니다.
            // 시작점이 50인데 hi가 49면 시작점을 못 밟습니다.
            if (hi < grid[0][0]) continue;

            // 위 조건으로 인해 [lo, hi] 구간에는 무조건 시작점 값이 포함됩니다.
            // 이제 BFS로 끝까지 갈 수 있는지 확인만 하면 됩니다.
            if (canGo(lo, hi)) {
                cout << diff; // 가능한 최소 차이를 찾음
                return 0;     // 즉시 종료
            }
        }
    }

    return 0;
}