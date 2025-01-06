#include <iostream>
using namespace std;

int n, m, q;
int a[104][104];

// 행의 원소를 왼쪽으로 이동
void moveleft(int idx) {
    int temp = a[idx][0];
    for (int i = 0; i < m - 1; i++) {
        a[idx][i] = a[idx][i + 1];
    }
    a[idx][m - 1] = temp;
}

// 행의 원소를 오른쪽으로 이동
void moveright(int idx) {
    int temp = a[idx][m - 1];
    for (int i = m - 1; i > 0; i--) {
        a[idx][i] = a[idx][i - 1];
    }
    a[idx][0] = temp;
}

// 두 행이 같은 열에 같은 숫자를 갖는지 확인
bool jeonpa(int gijoon_idx, int idx) {
    for (int i = 0; i < m; i++) {
        if (a[gijoon_idx][i] == a[idx][i]) {
            return true;
        }
    }
    return false;
}

// 방향을 반전
char flip(char c) {
    return (c == 'L') ? 'R' : 'L';
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (q--) {
        int idx;
        char c;
        cin >> idx >> c;
        idx--;  // 1-based index를 0-based index로 변환

        // 현재 행을 이동
        if (c == 'L') {
            moveright(idx);
        } else {
            moveleft(idx);
        }

        char current_dir = flip(c);
        int gijoon = idx;

        // 위쪽 전파
        for (int j = idx - 1; j >= 0; j--) {
            if (jeonpa(gijoon, j)) {
                if (current_dir == 'L') {
                    moveright(j);
                } else {
                    moveleft(j);
                }
                current_dir = flip(current_dir);
                gijoon = j;
            } else {
                break;
            }
        }

        current_dir = flip(c);  // 방향을 원래대로 설정
        gijoon = idx;

        // 아래쪽 전파
        for (int j = idx + 1; j < n; j++) {
            if (jeonpa(gijoon, j)) {
                if (current_dir == 'L') {
                    moveright(j);
                } else {
                    moveleft(j);
                }
                current_dir = flip(current_dir);
                gijoon = j;
            } else {
                break;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
