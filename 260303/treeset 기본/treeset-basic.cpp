
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
        cin >> command[i];
        if (command[i] == "add" || command[i] == "remove" ||
            command[i] == "find" || command[i] == "lower_bound" ||
            command[i] == "upper_bound") {
            cin >> x[i];
        }
        if(command[i] == "add")
        {
            s.insert(x[i]);
        }
        if(command[i] == "remove")
        {
            s.erase(x[i]);
        }
        if(command[i] == "find")
        {   
           if(s.find(x[i]) !=s.end())
           {
                cout <<"true"<<endl;
           }
           else
           {
                cout << "false"<<endl;
           }
        }
        if(command[i] == "lower_bound")
        {
            if(s.lower_bound(x[i]) != s.end())
            {
                cout << *s.lower_bound(x[i])<<endl;
            }
            else
            {
                cout <<"None"<<endl;
            }
        }
        if(command[i] == "upper_bound")
        {
            if(s.upper_bound(x[i]) != s.end())
            {
                cout << *s.upper_bound(x[i])<<endl;
            }
            else
            {
                cout << "None"<<endl;
            }
        }
        if(command[i] == "largest")
        {
            if(!s.empty())
            {
                cout << *s.rbegin()<<endl;
            }
            else
            {
                cout << "None"<<endl;
            }
        }
        if(command[i] == "smallest")
        {
            if(!s.empty())
            {
                cout << *s.begin()<<endl;
            }
            else
            {
                cout << "None"<<endl;
            }
        }

    }

    // Please write your code here.

    return 0;
}

