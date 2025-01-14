#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cnt;
int n;

vector<int> v;

bool check()
{
    for(int i = 0 ; i < n ;)
    {
        int length = v[i];
        if(i+length > n)
        {
            return false;
        }
        for(int j = i ; j < i+length ; j++)
        {
            if(v[i] != v[j]) return false;
        }
        i+= length;
    }
    return true;
}

void choose(int num)
{
    if(num == n+1)
    {
        if(check())
        {
            cnt++;
        }
        return ;
    }

    for(int i=1 ; i<= 4;i++)
    {
        v.push_back(i);
        choose(num+1);
        v.pop_back();
    }
}


int main() {
    cin >> n;

    choose(1);
    // Write your code here!
    cout << cnt;
    return 0;
}
