#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int visited[10];

void print()
{
    for(int i : v)
    {
        cout <<i <<" ";
    }
    cout << endl;
}

void sol(int idx)
{

    if(idx == n)
    {
        print ();
        return ;
    }

    for(int i = n ; i >=1 ; i--)
    {
        if(visited[i]) continue;

        v.push_back(i);
        visited[i] = true;

        sol(idx+1);

        v.pop_back();
        visited[i] = false;
    }
}



int main() {
    cin >> n;

    sol(0);

    // Write your code here!

    return 0;
}
