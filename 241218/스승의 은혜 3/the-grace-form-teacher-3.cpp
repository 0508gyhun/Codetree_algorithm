#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int a[1004][2];
int n,b;

int main() {
    cin >> n >> b;

    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    int mx = 0;
    for(int i = 0; i < n; i++) {
        int tmpsum = 0;
        int cnt = 0;
        
        // 선물 가격+배송비 배열 생성
        int tmp[1004];
        for(int j = 0; j < n; j++) {
            // 현재 학생의 선물만 반값 처리
            if(j == i) {
                tmp[j] = a[j][0]/2 + a[j][1];
            } else {
                tmp[j] = a[j][0] + a[j][1];
            }
        }
        
        // 가격 오름차순 정렬
        sort(tmp, tmp+n);
        
        // 예산 내 최대 구매 가능 학생 수 계산
        for(int j = 0; j < n; j++) {
            if(tmpsum + tmp[j] <= b) {
                tmpsum += tmp[j];
                cnt++;
            }
        }
        
        mx = max(mx, cnt);
    }
    
    cout << mx;
    return 0;
}