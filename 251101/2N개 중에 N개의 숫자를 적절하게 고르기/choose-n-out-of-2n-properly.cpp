#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int num[20];
vector<int> v;
int total;
int mn = INT_MAX;

void prt() {
    int sum = 0;
    for(int i : v) {
        // cout <<i <<" ";
        sum+=i;
    }
    // cout << endl;

    int sum1 = total - sum;
    mn = min(mn,abs(sum1-sum));
}

void go(int idx, int cnt) 
{
    if(idx == 2*n){
        if(cnt == n) {
            prt();
        }
        return;
    } 
    

    v.push_back(num[idx]);
    go(idx+1, cnt+1);
    v.pop_back();

    go(idx+1, cnt);
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total+=num[i];
    }


    go(0,0);
    cout << mn;
    // Please write your code here.

    return 0;
}
