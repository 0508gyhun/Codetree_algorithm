#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];
map <int,int> mp;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "add") {
            cin >> k[i] >> v[i];
            mp[k[i]] = v[i];

        } else if (cmd[i] == "remove") {
            cin >> k[i];
            mp.erase(k[i]);
        }
        else if( cmd[i] == "find" )
        {
            cin >> k[i];
            if(mp.find(k[i]) == mp.end())
            {
                cout << "None"<<endl;
            }
            else
            {
                cout << mp[k[i]]<<endl;
            }
        }
        else
        {
            if(mp.empty())
            {
                cout <<"None"<<endl;
            }
            else
            {
                for(auto i : mp)
                {
                    cout << i.second <<" ";
                }
                    cout << endl;
            }
            
        }
    }

    // Please write your code here.

    return 0;
}
