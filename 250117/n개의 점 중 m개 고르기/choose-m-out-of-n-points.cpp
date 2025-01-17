#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int x[20], y[20];
vector<int> v;  // n개 중 m개 선택한 점들의 인덱스 저장
int mn = INT_MAX;  // 최종 답 (최대 거리들 중 최소값)

// 두 점 사이의 거리 제곱 계산
long long dif(int n1, int n2) {
    long long s1 = (long long)(x[n1] - x[n2]) * (x[n1] - x[n2]);
    long long s2 = (long long)(y[n1] - y[n2]) * (y[n1] - y[n2]);
    return s1 + s2;
}

// 선택된 m개의 점들 중 가장 먼 거리 찾기
int findMaxDistance() {
    int maxDist = 0;
    // 선택된 모든 점들 쌍에 대해 거리 계산
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            maxDist = max(maxDist, (int)dif(v[i], v[j]));
        }
    }
    return maxDist;
}

// n개 중 m개 선택하는 조합
void solve(int idx, int cnt) {
    if(cnt == m) {
        // m개가 선택되면 그 중 최대 거리 계산
        int maxDist = findMaxDistance();
        // 지금까지의 최소값과 비교하여 갱신
        mn = min(mn, maxDist);
        return;
    }
    
    for(int i = idx; i < n; i++) {
        v.push_back(i);
        solve(i + 1, cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    solve(0, 0);
    cout << mn;
    
    return 0;
}