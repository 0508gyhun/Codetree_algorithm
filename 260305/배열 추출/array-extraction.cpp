#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int x[200000];

priority_queue <int> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        int dir= x[i];

        if(dir == 0)
        {
            if(pq.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << pq.top()<< endl;
                pq.pop();   
            }
        }
        else
        {
            pq.push(x[i]);
        }
    }

    // Please write your code here.

    return 0;
}
