#include <iostream>
using namespace std;

int a[1000001], b[1000001];  // 배열 크기를 더 안전하게 설정
int n, m;

int main() {
    ios_base::sync_with_stdio(false);  // 입출력 속도 개선
    cin.tie(NULL);
    
    cin >> n >> m;
    
    // A의 위치 계산
    int totalTime = 0;
    for(int i = 0; i < n; i++) {
        int v, t;
        cin >> v >> t;
        for(int j = 0; j < t; j++) {
            totalTime++;
            a[totalTime] = a[totalTime-1] + v;
        }
    }
    
    // B의 위치 계산
    int currentTime = 0;
    for(int i = 0; i < m; i++) {
        int v, t;
        cin >> v >> t;
        for(int j = 0; j < t; j++) {
            currentTime++;
            b[currentTime] = b[currentTime-1] + v;
        }
    }
    
    // 리더 변경 횟수 계산
    int changes = 0;
    int currentLeader = 0;  // 0: 초기상태, 1: A리더, 2: B리더, 3: 동률
    
    for(int i = 1; i <= totalTime; i++) {
        int newLeader;
        if(a[i] > b[i]) {
            newLeader = 1;
        }
        else if(a[i] < b[i]) {
            newLeader = 2;
        }
        else {
            newLeader = 3;
        }
        
        if(newLeader != currentLeader) {
            changes++;
            currentLeader = newLeader;
        }
    }
    
    cout << changes;
    return 0;
}