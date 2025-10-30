#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int K, N;

bool prt() {
    int cnt = 1;
    for(int i = 0 ; i <v.size()-1 ; i++) {
        if(cnt == 3) return false;
        if(v[i] == v[i+1]) {
            cnt++;
        }
        else {
            cnt = 1;
        }
    }
    if(cnt == 3) return false;
    return true;
}

void go(int idx) {
    if(idx == N) {
        if(prt()){
            for(int i : v) {
                cout << i <<" ";
            }
            cout << endl;
        };
        return ; 
    }

    for(int i = 1 ; i <= K ; i++) {
        
            v.push_back(i);
            go(idx+1);
            v.pop_back();
        
    }

}


int main() {
    cin >> K >> N;


    go(0);
    // Please write your code here.

    return 0;
}
