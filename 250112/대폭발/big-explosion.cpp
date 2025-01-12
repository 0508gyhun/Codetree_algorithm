#include <iostream>
#include <vector>
using namespace std;

int n, m, r, c;
int a[101][101]; // 현재 폭탄 상태
vector<pair<int, int>> v; // 폭탄 위치 저장
int dy[4] = {-1, 0, 1, 0}; // 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1};

// 범위 확인 함수
bool inRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

// 폭탄 확장 함수
void setbomb(int t) {
    for (auto k : v) { // 현재 폭탄 위치를 기준으로 확장
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= t; j++) { // 거리 t만큼 확장
                int ny = k.first + j * dy[i];
                int nx = k.second + j * dx[i];
                if (!inRange(ny, nx)) break; // 범위를 벗어나면 중단
                a[ny][nx] = 1; // 폭탄을 확장
            }
        }
    }
}

// 폭탄 위치 검색 함수
void searchbomb() {
    v.clear(); // 이전 폭탄 위치 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) { // 폭탄이 있는 위치 저장
                v.push_back({i, j});
            }
        }
    }
}

// 현재 상태 출력 함수
void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> n >> m >> r >> c;

    r--; // 0-based 인덱스로 변환
    c--;
    a[r][c] = 1; // 초기 폭탄 위치 설정

    for (int p = 1; p <= m; p++) { // m번 반복
        searchbomb(); // 현재 폭탄 위치 저장
        setbomb(1 << (p - 1)); // 거리 2^(p-1)로 확장
    }

    int ans = 0;
    for (int i = 0; i < n; i++) { // 폭탄이 설치된 칸의 개수 계산
        for (int j = 0; j < n; j++) {
            ans += a[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}
