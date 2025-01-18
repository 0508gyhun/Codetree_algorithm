#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10][10];
vector<int> v;
int visited[11];

int getMin()
{
    int mn = INT_MAX;
    for(int i = 0 ; i < n ; i++)
    {
        mn = min(mn, a[i][v[i]]);
    }
    return mn;
}
int mx = INT_MIN;
void sol(int rowidx)
{
    if(rowidx == n)
    {
        int ans = getMin();
        mx = max(mx,ans);
        return ;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i]) continue;
        v.push_back(i);
        visited[i] = true;

        sol(rowidx+1);

        v.pop_back();
        visited[i] = false;
    }
}

// 각 열의 인덱스를 순열로/
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    sol(0);
    cout << mx;
    // Write your code here!

    return 0;
}
