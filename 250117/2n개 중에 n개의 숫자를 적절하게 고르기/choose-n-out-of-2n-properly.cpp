#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int total;
int n;
int num[20];
// 2n개 중에서 n 개 선택
//전체 합에서 빼기 
vector<int> v;

int mn = INT_MAX;
int cal()
{
    int totalnum = total; 
    int select = 0;
    for(int i : v)
    {
       // cout << i <<" ";
        select += i;
    }
    // cout << endl;
    totalnum = totalnum-select;
    cout << totalnum <<" "<<select<<endl;
    return abs(totalnum-select);
}
void sol(int idx, int cnt)
{
    if(idx == 2*n)
    {
        if(cnt == n) mn = min(mn,cal());
        return;
    }


    v.push_back(num[idx]);
    sol(idx+1,cnt+1);
    v.pop_back();

    sol(idx+1,cnt);
}




int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total+=num[i];
    }


    sol(0,0);
    cout << mn;
    // Write your code here!

    return 0;
}
