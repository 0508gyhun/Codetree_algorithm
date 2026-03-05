#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];
queue<int> q;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        q.push(arr[i]);
    }
    double ans = INT_MIN;
    for(int i = 1 ; i <= N-2 ; i++)
    {
        q.pop();
        queue <int> q1;
        q1 = q;
        priority_queue <int> pq;
        while(q1.size())
        {
            int a = q1.front();
            q1.pop();
            pq.push(-a);
        }
        pq.pop(); // 가장 작은 숫자 제외
        int pqs = pq.size();
        long long total = 0;
        while(pq.size())
        {
            total += (-pq.top());
            pq.pop();
        }
        ans = max(ans, total / pqs );
    }
    cout << fixed << setprecision(2) << ans ;
    
    // Please write your code here.

    return 0;
}
