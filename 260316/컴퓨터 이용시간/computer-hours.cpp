#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int p[100004], q[100004];
vector<tuple<int,int,int>> v;
priority_queue<int> pq;;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i] >> q[i];
        v.push_back({p[i], 1, i});
        v.push_back({q[i],-1,i});
    }

    sort(v.begin(), v.end());

    for(int i = 1 ; i <= n ;i++)
    {
        pq.push(-i);
    }
    int sge[100004] = {0,};
    for(int i = 0 ; i < 2 * n ; i++)
    {
        int x,y,idx;
        tie(x,y,idx) = v[i];

        if(y == 1) 
        {
            int top = pq.top();
            pq.pop();

            sge[idx] = -top;
        }
        else {
            int cn = sge[idx];
            pq.push(-cn);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << sge[i] <<" ";
    }

    // Please write your code here.

    return 0;
}
