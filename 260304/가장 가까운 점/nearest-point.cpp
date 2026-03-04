#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];

priority_queue<pair<int,int>> pq;
priority_queue<pair<int,int>> pq2;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        pq.push({-x[i],-y[i]});
    }

    for(int i = 0; i < m ; i++)
    {
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        pq.push({a-2,b-2});
    }

    while (!pq.empty()) {
    int a = pq.top().first;
    int b = pq.top().second;
    pq.pop();
    
    // pq에 -를 붙여서 넣었으므로, 다시 -를 붙이면 원래 양수값이 됩니다.
    pq2.push({-a, -b});
    }

    // int c = pq.top().first;
    // int d = pq.top().second;

    // cout <<-c + (-d) <<endl;
    pair<int,int> ansp ={0,0};
    int ans = INT_MAX;
    for(int i = 0 ; i < n ;i++)
    {
        int a = pq2.top().first;
        int b = pq2.top().second;
        pq2.pop();
        if(ans > a+b)
        {
            ans = a+b;
            ansp.first = a;
            ansp.second = b;
        }
    }
    cout << ansp.first<<" "<<ansp.second<<endl;



    // Please write your code here.

    return 0;
}
