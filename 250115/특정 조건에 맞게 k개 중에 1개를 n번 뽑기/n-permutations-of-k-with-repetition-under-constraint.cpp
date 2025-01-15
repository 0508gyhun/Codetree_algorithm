#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int K, N;
vector<int> v;


void print()
{
    for(int i : v)
    {
        cout << i<<" ";
    }
    cout << endl;
}

void sol(int currnum)
{
    if(currnum == N)
    {
        print();
        return ;
    }

    for(int i = 1 ; i<= K ; i++)
    {

        if(currnum>=2 && v[currnum-1] == i && v[currnum-2] == i)
        {
            continue;
            
        }
        else
        {
            v.push_back(i);
            sol(currnum+1);
            v.pop_back();
        }
        
    }
}

int main() {
    cin >> K >> N;


    sol(0);
    // Write your code here!

    return 0;
}
