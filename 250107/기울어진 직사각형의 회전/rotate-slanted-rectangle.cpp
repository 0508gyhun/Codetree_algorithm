#include <iostream>
#include <vector>
using namespace std;

int n;
int a[101][101];
int r, c, m1, m2, m3, m4;
int dir;

void sol(int r, int c, int m1, int m2, int m3, int m4, int dir) {
    // 이동 방향
    int dy[4] = {-1, -1, 1, 1};
    int dx[4] = {1, -1, -1, 1};
    int dr[4] = {m1, m2, m3, m4};

    // 테두리 값 추출
    int str = r, stc = c; // 시작점 저장
    vector<int> v;
    v.push_back(a[r][c]);

    for (int i = 0; i < 4; i++) { // 각 방향으로 이동
        for (int j = 0; j < dr[i]; j++) {
            r += dy[i];
            c += dx[i];
            v.push_back(a[r][c]);
        }
    }

    // 마지막 중복 값 제거
    v.pop_back();

    // 방향에 따라 벡터를 이동
    if (dir == 0) { // 오른쪽으로 밀기
        int temp = v.back();
        for (int i = v.size() - 1; i > 0; i--) {
            v[i] = v[i - 1];
        }
        v[0] = temp;
    } else if (dir == 1) { // 왼쪽으로 밀기
        int temp = v[0];
        for (int i = 0; i < v.size() - 1; i++) {
            v[i] = v[i + 1];
        }
        v[v.size() - 1] = temp;
    }

    // 테두리 값 갱신
    r = str; c = stc; // 시작점 복원
    a[r][c] = v[0];
    int idx = 1;

    for (int i = 0; i < 4; i++) { // 각 방향으로 이동
        for (int j = 0; j < dr[i]; j++) {
            r += dy[i];
            c += dx[i];
            if(idx != v.size()) a[r][c] = v[idx++];
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n; // 격자 크기 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // 입력: 시작점, 각 변의 길이, 방향
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    r--; c--; // 1-based index를 0-based로 변환

    sol(r, c, m1, m2, m3, m4, dir);

    return 0;
}
