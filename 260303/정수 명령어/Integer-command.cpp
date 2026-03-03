#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T;
int k;
char command[100000];
int n[100000];

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> k;
        set <int> s;
        for (int i = 0; i < k; i++) {
            cin >> command[i] >> n[i];
            if(command[i] == 'I')
            {
                s.insert(n[i]);
            }
            else {
                if(n[i] == 1)
                {
                    if(s.empty() == false)
                    {
                        s.erase(*s.rbegin());
                    }
                }
                else if( n[i] == -1)
                {
                    if(s.empty() == false)
                    {
                        s.erase(*s.begin());
                    }
                }
            }
        }

     if(s.empty() )
            {
                cout <<"EMPTY" << endl;
            }
            else {
                cout << *s.rbegin() <<" "<<*s.begin()<<endl;
            }
    // Please write your code here.

    }

    return 0;
}

