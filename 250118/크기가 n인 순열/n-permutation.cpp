#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int visited[9];
vector <int> v;
void print()
{
    for(int i: v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void sol(int idx)
{
 
    if(idx == n+1)
    {
        print();
        return ;
    }

    for(int i = 1 ; i <=n ; i++)
    {
        if(visited[i] == true)
        {
            continue;
        }
        v.push_back(i);
        visited[i] = true;

        sol(idx+1);

        v.pop_back();
        visited[i] = false;
    }
}


int main() {
    cin >> n;


    sol(1);
    // Write your code here!

    return 0;
}
//1-n 을 사용해서 수열, 사전순 , 오름차순..
