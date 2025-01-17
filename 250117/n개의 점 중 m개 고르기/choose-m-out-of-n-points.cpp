#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int x[20], y[20];
vector<int> v;  // n개 중 m개 선택한 점들의 인덱스 저장
vector<int> v2; // m개 중 2개 선택한 점들의 인덱스 저장
int mn = INT_MAX;

int dif(int n1, int n2) {
    int s1 = (x[n1]-x[n2]) * (x[n1]-x[n2]);
    int s2 = (y[n1]-y[n2]) * (y[n1]-y[n2]);
    return s1 + s2;
}

int cal() {
    int n1 = v2[0];
    int n2 = v2[1];
    return dif(n1,n2);
}

void sol2(int idx, int cnt) {
    if(idx == v.size()) {
        if(cnt == 2) {
            mn = min(mn,cal());
        }
        return;
    }
    
    v2.push_back(v[idx]);
    sol2(idx+1,cnt+1);
    v2.pop_back();
    
    sol2(idx+1,cnt);
}

void print() {
    sol2(0,0);
}

void sol(int idx, int cnt) {
    if(idx == n) {
        if(cnt == m) print();
        return;
    }
    
    v.push_back(idx);
    sol(idx+1, cnt+1);
    v.pop_back();
    
    sol(idx+1, cnt);
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    sol(0,0);
    cout << mn;
    
    return 0;
}