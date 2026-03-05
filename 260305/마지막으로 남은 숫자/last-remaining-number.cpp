#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100000];
priority_queue <int> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    while(pq.size() >=2)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        if(a != b)
        {
            pq.push(a-b);
        }
    }

    if(pq.size() == 1)cout << pq.top()<< endl;
    else{
        cout << -1 << endl;
    }

    // Please write your code here.

    return 0;
}
