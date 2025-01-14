#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int K, N;
vector<int > v;

void print()
{
    for(int i : v)
    {
        cout << i<<" ";
    }
    cout << endl;
}

void choose(int num)
{
    if( num == N+1)
    {
        print();
        return ;
    }

    for(int i = 1 ; i <= K ; i++)
    {
        v.push_back(i);
        choose(num+1);
        v.pop_back();
    }
}

int main() {
    cin >> K >> N;

    // Write your code here!

    choose(1);

    return 0;
}
