#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[104][104];
int r1, c1, r2, c2;

void mvright(int r1, int c1, int r2, int c2) {
    vector<int> bound;

    // up
    for (int i = c1; i <= c2; i++) {
        bound.push_back(a[r1][i]);
    }
    // right
    for (int i = r1 + 1; i <= r2; i++) {
        bound.push_back(a[i][c2]);
    }
    // down
    for (int i = c2 - 1; i >= c1; i--) {
        bound.push_back(a[r2][i]);
    }
    // left
    for (int i = r2 - 1; i > r1; i--) {
        bound.push_back(a[i][c1]);
    }

    // Rotate right
    int sz = bound.size();
    int temp = bound[sz - 1];
    for (int i = sz - 1; i > 0; i--) {
        bound[i] = bound[i - 1];
    }
    bound[0] = temp;

    // Reassign back to grid
    int idx = 0;
    for (int i = c1; i <= c2; i++) {
        a[r1][i] = bound[idx++];
    }
    for (int i = r1 + 1; i <= r2; i++) {
        a[i][c2] = bound[idx++];
    }
    for (int i = c2 - 1; i >= c1; i--) {
        a[r2][i] = bound[idx++];
    }
    for (int i = r2 - 1; i > r1; i--) {
        a[i][c1] = bound[idx++];
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}

void sol(int i, int j) {
    int sum = a[i][j];
    int cnt = 1;

    // 위쪽
    if (i - 1 >= 0) {
        sum += a[i - 1][j];
        cnt++;
    }
    // 아래쪽
    if (i + 1 < n) {
        sum += a[i + 1][j];
        cnt++;
    }
    // 왼쪽
    if (j - 1 >= 0) {
        sum += a[i][j - 1];
        cnt++;
    }
    // 오른쪽
    if (j + 1 < m) {
        sum += a[i][j + 1];
        cnt++;
    }

    // 평균 계산
    b[i][j] = sum / cnt;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        // 테두리 회전
        mvright(r1, c1, r2, c2);

        int b[104][104] = {0,};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[i][j];
         
            }
        }



        // 내부 값 업데이트
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                sol(i, j);
            }
        }

        // 출력 중간 결과
        cout << "\nResult:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
