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
            int numn
            if(i == 0 ) numn = num-1;
            if(i == 1) numn = num +1;
            if(i == 2 && numn % 2 == 0) num = num /2;
            if(i == 3 && numn % 3 == 0) num = num /3;
            if(numn>=0 && numn <= 1000000 &&visited[numn] == 0) 
            {
                visited[numn] = 1;
                q.push({numn, cnt+1});
            }


        }
    }
    return 0;
}
