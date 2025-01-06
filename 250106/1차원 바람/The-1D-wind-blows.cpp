#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
int a[104][104];

bool jeonpa(int gijoon_idx, int idx) {
    for(int i = 0; i < m; i++) {
        if(a[gijoon_idx][i] != a[idx][i]) {
            return false;
        }
    }
    return true;
}

void moveleft(int idx) {
    int temp = a[idx][0];
    for(int i = 0; i < m-1; i++) {
        a[idx][i] = a[idx][i+1];
    }
    a[idx][m-1] = temp;
}

void moveright(int idx) {
    int temp = a[idx][m-1];
    for(int i = m-1; i > 0; i--) {
        a[idx][i] = a[idx][i-1];
    }
    a[idx][0] = temp;
}

int main() {
    cin >> n >> m >> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < q; i++) {
        int idx;
        char c;
        cin >> idx >> c;
        idx--;
        
        vector<int> affected;
        affected.push_back(idx);
        
        // 영향 받는 행들을 순서대로 찾기
        for(int j = 0; j < n; j++) {
            if(j != idx) {
                for(const int& prev : affected) {
                    if(jeonpa(prev, j)) {
                        affected.push_back(j);
                        break;
                    }
                }
            }
        }
        
        // 실제 이동 수행
        bool isRight = (c == 'L');  // L이면 오른쪽으로, R이면 왼쪽으로
        for(size_t j = 0; j < affected.size(); j++) {
            if(isRight) {
                moveright(affected[j]);
            } else {
                moveleft(affected[j]);
            }
            isRight = !isRight;  // 방향 전환
        }
    }
    
    // 결과 출력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}