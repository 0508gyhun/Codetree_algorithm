#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int a[10][10];
vector<int> v;
int visited[11];

int mx = 0;
void sol(int rowidx)
{
    if (rowidx == n)
    {   int sum = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            sum+=a[i][v[i]];
        }
        mx = max(mx,sum);
    }
    // 0 - n    까지의 어떤 열에 수를 선캑할 것인지.
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



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    sol(0);
    // Write your code here!
    cout << mx;

    return 0;
}
