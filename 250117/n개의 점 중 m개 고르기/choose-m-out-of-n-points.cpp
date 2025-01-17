#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int x[20], y[20];
vector<int> v;  // n개 중 m개 선택한 점들의 인덱스 저장
vector<int> selected;  // m개 중 2개 선택한 실제 인덱스
int mn = INT_MAX;

// 두 점 사이의 거리 제곱 계산
long long dif(int n1, int n2) {
    long long s1 = (long long)(x[n1] - x[n2]) * (x[n1] - x[n2]);
    long long s2 = (long long)(y[n1] - y[n2]) * (y[n1] - y[n2]);
    return s1 + s2;
}

// 선택된 두 점 사이의 거리 계산
long long cal() {
    return dif(selected[0], selected[1]);
}

// m개 중 2개 선택
void sol2(int idx, int cnt) {
    if(cnt == 2) {
        mn = min(mn, (int)cal());
        return;
    }
    
    for(int i = idx; i < v.size(); i++) {
        selected.push_back(v[i]);
        sol2(i + 1, cnt + 1);
        selected.pop_back();
    }
}

void print() {
    selected.clear();
    sol2(0, 0);
}

// n개 중 m개 선택
void sol(int idx, int cnt) {
    if(cnt == m) {
        print();
        return;
    }
    
    for(int i = idx; i < n; i++) {
        v.push_back(i);
        sol(i + 1, cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    sol(0, 0);
    cout << mn;
    
    return 0;
}