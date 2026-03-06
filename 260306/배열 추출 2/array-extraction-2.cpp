#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n;
int x[MAX_N];
priority_queue <pair<int,int>> pq;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        int a = x[i];
        
        if(a != 0)
        {
            
            pq.push({-1 * abs(x[i]), -x[i]});
             
          
        }
        else
        {
            if(pq.empty())
            {
                cout << 0<< endl;
                continue;
            }
            else
            {
                int k = pq.top().second;
                pq.pop();

                cout << -k<< endl;

            }
        }
    }

    // Please write your code here.

    return 0;
}
