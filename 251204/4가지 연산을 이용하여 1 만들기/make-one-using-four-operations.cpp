#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int visited[1000004];
int N;

queue<pair<int,int>> q;

int main() {
    cin >> N;

    // Please write your code here.

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
            if(i == 0 ) num = num-1;
            if(i == 1) num = num +1;
            if(i == 2 && num % 2 == 0) num = num /2;
            if(i == 3 && num % 3 == 0) num = num /3;
            if(num>=1 && num <= 1000000 &&visited[num] == 0) 
            {
                visited[num] = 1;
                q.push({num, cnt+1});
            }


        }
    }
    return 0;
}
