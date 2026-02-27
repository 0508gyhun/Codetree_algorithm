#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n, k;
int arr[100000];
map <int,int> mp;

bool cmp (const pair<int,int> &a ,  const pair<int,int> &b)
{
    if(a.second == b.second) return a.first > b.first ;

    return a.second > b.second;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;

    }   

    vector<pair<int,int>> v (mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp); 
    int cnt = 0;
  

    for(auto i : v)
    {
        // cout << i.first<<" ";
        if(cnt < k)
        {
            cnt++;
            cout <<i.first<<" ";
        }
    }
    // Please write your code here.

    return 0;
}
