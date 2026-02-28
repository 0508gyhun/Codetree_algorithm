#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
string command[100000];
int x[100000];
set <int> s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
        if(command[i] == "add")
        {
            s.insert(x[i]);
        }
        else if(command[i] == "remove")
        {
            s.erase(x[i]);
        }
        else
        {
            if(s.find(x[i]) != s.end())
            {
                cout<<"true"<<endl;
            }
            else
            {
                cout<<"false"<<endl;
            }

        }
    }

    // Please write your code here.

    return 0;
}
