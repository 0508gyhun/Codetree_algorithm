#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int visited[1000004];
int N;

queue<pair<int,int>> q;

int main() {
    cin >> N;

    // Please write your code here.
    if (N == 1) { // 이미 1이면 0번
        cout << 0;
        return 0;
    }

    visited[N] = 1;
    q.push({N,0});

    while(q.size()) 
    {
        int num, cnt;
        tie(num,cnt) = q.front();
        q.pop();
        if(num == 1)
        {
            cout << cnt;
            return 0;
        }
        for(int i = 0 ; i < 4 ; i++) 
        {
            int next_num = 0;
            if(i == 0) next_num = num - 1;
            else if(i == 1) next_num = num + 1;
            else if(i == 2) {
                if(num % 2 == 0) next_num = num / 2;
                else continue; // 2로 안 나눠지면 이번 턴(i=2)은 무시
            }
            else if(i == 3) {
                if(num % 3 == 0) next_num = num / 3;
                else continue; // 3으로 안 나눠지면 이번 턴(i=3)은 무시
            }
            if(next_num >= 0 && next_num <= 1000000 && visited[next_num] == 0) 
            {
                visited[next_num] = 1;
                q.push({next_num, cnt + 1});
            }


        }
    }
    return 0;
}
