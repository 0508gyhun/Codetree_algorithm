#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

void print()
{
    for(int i : v )
    {
        cout << i <<" ";
    }
    cout << endl;
}

void sol(int curnum,int cnt)
{
    if(curnum == N+1)
    {
        if(cnt == M) print();
        return;
    }

    v.push_back(curnum);
    sol(curnum+1,cnt+1);
    v.pop_back();

    sol(curnum+1, cnt);
   
}



int main() {
    cin >> N >> M;  


    sol(1,0);

    // Write your code here!

    return 0;
}
