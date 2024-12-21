#include <iostream>
using namespace std;

int n;
int a[11];
int b[11];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int j = 1; j <= 5000; j++) { // 1부터 5000까지 확인
        bool flag = true; // 조건 만족 여부를 확인
        int current = j;  // j 값을 변경하지 않도록 별도 변수 사용

        for (int i = 0; i < n; i++) {
            current *= 2; // 값을 2배로 증가
            if (!(a[i] <= current && current <= b[i])) {
                flag = false; // 조건을 만족하지 않으면 false
                break;
            }
        }

        if (flag) {
            cout << j << endl; // 조건을 만족하는 j 값을 출력
            return 0;          // 프로그램 종료
        }
    }

    return 0;
}
