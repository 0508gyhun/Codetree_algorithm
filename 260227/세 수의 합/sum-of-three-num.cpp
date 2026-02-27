#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n, k;
int arr[1004];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int total = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int target = k - arr[i];

        unordered_map <int,int> um;

        for(int j = i+1 ; j < n ; j++)
        {
            int need = target - arr[j];

            if(um.count(need) > 0 )
            {
                total += um.count(need);
            }

            um[arr[j]]++;
        } 
    }

    cout <<total;
    // Please write your code here.

    return 0;
}
