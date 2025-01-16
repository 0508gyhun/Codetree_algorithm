#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int num[10];
int mn = INT_MAX;
void sol(int curnum, int local)
{
    if(local >= n) return;
    if(local == n-1)
    {
        mn = min(mn,curnum);
        return ;
    }

    int dist = num[local] ;

    for(int i = 1 ; i <=dist; i++)
    {
        sol(curnum+1, local+i);
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sol(0,0);

    if (mn == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << mn << endl;
    }

    return 0;
}
