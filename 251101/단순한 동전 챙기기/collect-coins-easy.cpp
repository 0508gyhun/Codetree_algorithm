#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
char grid[20][20];

pair<int,int> st;
pair<int,int> ed;
vector<pair<int,int>> num;
vector<pair<int,int>> v;
int n_num;

int Dist(pair<int,int> st, pair<int,int> ed) {
    return abs(ed.first-st.first) + abs(st.second - ed.second);
}

int prt() {
    // cout <<"its prt"<< endl;
    // for(auto i : v) {
    //     // cout << i.first <<" "<<i.second<< endl;
    //     cout << grid[i.first][i.second] << endl;
    // }
    // cout << endl;

    int num_moves = Dist(st, v[0]);
    for(int i = 0 ; i < 2 ; i++) {
        num_moves += Dist(v[i], v[i+1]);
    }
    num_moves+= Dist(v[2],ed);

    return num_moves;
}
int mn = INT_MAX;
void go(int idx, int cnt) {
    if(idx == n_num) {
        if(cnt >= 3) {
            mn = min(mn,prt());
        }
        return ;
    }

    v.push_back(num[idx]);
    go(idx+1, cnt+1);
    v.pop_back();

    go(idx+1, cnt);
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                st.first = i;
                st.second = j;
            }
            else if (grid[i][j] == 'E') {
                ed.first = i;
                ed.second = j;
            }
        } 
    }

    for(int i = 1 ; i <= 9; i++) {
        for(int j = 0 ; j < N ; j++) {
            for(int k  = 0 ; k < N ; k++) {
                if( i == grid[j][k]-'0') num.push_back({j,k});
            }
        }
    }
    n_num = num.size();
    // cout << "num size " <<n_num<< endl;
    // cout << st.first << " "<< st.second << endl;
    // cout << ed.first << " "<< ed.second << endl;
    // cout << endl;

    // for(auto i : num) {
    //     cout << i.first <<" "<< i.second << endl;
    // }
    go(0,0);
    if(mn == INT_MAX) mn = -1;
    cout << mn;


    // Please write your code here.


    return 0;
}
