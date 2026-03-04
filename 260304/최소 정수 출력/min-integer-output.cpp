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
        if(x[i] != 0 )
        {
            pq.push(-x[i]);
        }
        else
        {
            if(!pq.empty())
            {
                cout << pq.top() * -1 <<endl;
                pq.pop();
            }
            else {
                cout << 0 <<endl;
            }
        }
    }

    // Please write your code here.

    return 0;
}
