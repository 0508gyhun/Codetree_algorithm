#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[200000];
int B[200000];
set <int> s1,s2;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        s1.insert(A[i]);
    }


    for (int i = 0; i < m; i++){
        cin >> B[i];
        s2.insert(B[i]);
    } 

    for(int i = 0 ; i < m ; i++)
    {
        if(s1.find(B[i]) != s1.end())
        {
            s1.erase(B[i]);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(s2.find(A[i]) != s2.end())
        {
            s2.erase(A[i]);
        }
    }
    cout <<s1.size()+s2.size();
    // Please write your code here.

    return 0;
}
