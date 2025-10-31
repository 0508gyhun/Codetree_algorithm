#include <iostream>

using namespace std;

int N, M;
//1-N 까지 중 m=3개
vector<int> v;
void go (int idx) {
    if(idx == m) {
        for(int i : v) {
            cout << i <<" ";
        }
        cout << endl;
    }
    for(int i = 1 ; i <= n ; i++) {
        v.push_back(i);
        go(idx+1)
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;


    go(0);
    // Please write your code here.

    return 0;
}
