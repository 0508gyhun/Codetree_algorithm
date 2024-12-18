#include <iostream>
#include <algorithm>
using namespace std;

int a[1004][2];
int n, b;

int main() {
    cin >> n >> b;

    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    int mx = 0;
    
    // 각 학생의 선물에 대해 반값 쿠폰 적용 시도
    for(int i = 0; i < n; i++) {
        int tmpsum = 0;
        int cnt = 0;
        
        // 임시 배열 복사 (원본 데이터 유지)
        int tmp[1004][2];
        for(int j = 0; j < n; j++) {
            tmp[j][0] = a[j][0];
            tmp[j][1] = a[j][1];
        }
        
        // 현재 학생의 선물 반값 할인
        tmp[i][0] /= 2;
        
        // 선물 및 배송비 정렬 (낮은 순)
        sort(tmp, tmp + n, [](const int* a, const int* b) {
            return (a[0] + a[1]) < (b[0] + b[1]);
        });
        
        // 예산 내에서 최대한 많은 선물 구매
        for(int j = 0; j < n; j++) {
            if(tmpsum + tmp[j][0] + tmp[j][1] <= b) {
                tmpsum += tmp[j][0] + tmp[j][1];
                cnt++;
            }
        }
        
        // 최대값 갱신
        mx = max(mx, cnt);
    }
    
    cout << mx;
    return 0;
}