#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];

priority_queue<tuple<int,int,int>> pq;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        pq.push({-(x[i] + y[i]), -x[i], -y[i]});
    }

    for(int i = 0; i < m ; i++)
    {
        int ig,a,b;
        tie(ig,a,b) = pq.top();
        a = -a;
        b = -b;
        pq.pop();
        a+=2;
        b+=2;
        pq.push(make_tuple(-(a+b),-a,-b));
    }

    
    // cout <<-c + (-d) <<endl;
  
  int lastx,lasty,ig;
  tie(ig,lastx,lasty) = pq.top();
  cout << -lastx <<" "<<-lasty;

    // Please write your code here.

    return 0;
}
