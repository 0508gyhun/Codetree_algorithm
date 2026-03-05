#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];
priority_queue <int> pq;
int sum; 
double max_avg;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    pq.push(-arr[N-1]);
    sum+=arr[N-1];

    for(int i = N-2 ; i >=1 ; i --)
    {
        pq.push(-arr[i]);
        sum+=arr[i];

        double avg = (double) (sum - (-pq.top())) / (N-i-1);

        if(max_avg <avg)
        {
            max_avg = avg;
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << max_avg;
    
    // Please write your code here.

    return 0;
}
