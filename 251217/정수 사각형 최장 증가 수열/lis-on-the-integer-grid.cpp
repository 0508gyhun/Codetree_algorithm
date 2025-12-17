#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int grid[505][505];
int dp[505][505]; // dp[x][y]: (x,y)에서 출발하는 최장 경로 길이

// 상하좌우 이동을 위한 방향 배열
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// (x, y)에서 시작해서 갈 수 있는 최대 길이를 리턴하는 함수
int FindMax(int x, int y) {
    // 1. 이미 계산한 적이 있다면(메모이제이션), 그 값을 바로 반환
    // 0이 아니라는 뜻은 이미 방문해서 계산을 마쳤다는 뜻입니다.
    if (dp[x][y] != 0) {
        return dp[x][y];
    }

    // 2. 기본 길이는 1 (자기 자신)
    int max_depth = 1;

    // 3. 상하좌우 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 격자 범위를 벗어나지 않고
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            // "나보다 큰 숫자"로만 이동 가능
            if (grid[nx][ny] > grid[x][y]) {
                // 재귀 호출: 이웃 칸(nx, ny)에서 갈 수 있는 최대 길이에
                // 내 걸음(1)을 더해서 갱신합니다.
                // 여러 방향 중 가장 큰 값을 선택(max)
                max_depth = max(max_depth, 1 + FindMax(nx, ny));
            }
        }
    }

    // 4. 계산된 최댓값을 DP 테이블에 저장하고 리턴
    return dp[x][y] = max_depth;
}

int main() {
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            dp[i][j] = 0; // DP 테이블 초기화 (아직 방문 안 함)
        }
    }

    // 모든 칸이 "출발점"이 될 수 있습니다.
    // 따라서 모든 칸에 대해 FindMax를 실행해보고, 그중 가장 큰 값이 정답입니다.
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, FindMax(i, j));
        }
    }

    cout << ans << endl;
    return 0;
}
