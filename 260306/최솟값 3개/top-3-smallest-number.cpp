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
        pq.push(-arr[i]);

        if(pq.size() < 3)
        {
            cout <<-1 << endl;
        }
        else
        {   
            int total = 1 ;
            int tmp[3] = {0,};
            for(int j = 0 ; j < 3; j++)
            {
                tmp[j] = -pq.top();
                total *= tmp[j];
                pq.pop();
            }
            cout << total << endl;

            for(int j = 0 ; j < 3 ; j ++)
            {
                pq.push(-tmp[j]);
            }
        }
    }

    // Please write your code here.

    return 0;
}
