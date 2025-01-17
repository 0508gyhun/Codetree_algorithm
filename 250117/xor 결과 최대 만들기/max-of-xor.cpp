#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n, m;
int a[20];
//n개 중 m 개 뽑기
string s[20];
//010
//100
//110
int mx = INT_MIN;
int ezinsoo()
{
    int sum = v[0] ;
    for(int i = 1 ; i < v.size() ; i++)
    {
        sum = sum^v[i];
    }
    //cout << sum;
    return sum;
     
}

void sol(int idx, int cnt)
{
    if(idx == n)
    {
        if(cnt == m){
           // print();
            mx = max(mx,ezinsoo());
        }
        return ;
    }

    v.push_back(a[idx]);
    sol(idx+1, cnt+1);
    v.pop_back();

    sol(idx+1,cnt);
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sol(0,0);
    cout << mx << endl;

    return 0;
}

