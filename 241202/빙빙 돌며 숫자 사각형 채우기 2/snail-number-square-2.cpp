#include <iostream>
using namespace std;

int dy[4] = {0, 1, 0, -1};  // 오른쪽, 아래, 왼쪽, 위 순서
int dx[4] = {1, 0, -1, 0};
int n, m;
int a[104][104];

int main() {
    cin >> n >> m;
    
    int y = 0, x = 0;  // 시작점 초기화
    int dir = 1;
    int cnt = 1;
    
    a[y][x] = cnt++;
    
    while (cnt <= n * m) {
        for (int k = 0; k < 4; k++) {  // 방향별 최대 이동 횟수 제한
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            // 범위를 벗어나거나 이미 채워진 칸이면 방향 전환
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] != 0) {
                dir = (dir + 1) % 4;
                continue;
            }
            
            y = ny;
            x = nx;
            a[y][x] = cnt++;
            
            // 모든 칸을 채웠으면 종료
            if (cnt > n * m) break;
        }
    }
    
    // 배열 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}