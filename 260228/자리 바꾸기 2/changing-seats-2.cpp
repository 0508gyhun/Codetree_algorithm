#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int a[100000], b[100000];
set <int> s[100004]; // i번 사람이 간 곳. 
int arr[100005];
int main() {
    cin >> N >> K;

    for(int i = 1 ; i <= N ; i++)
    {
        arr[i] = i;
        s[i].insert(i);
    }
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
    }
    

    for(int j = 0 ; j < 3 ; j++)
    {
        for(int i = 0 ; i < K ; i++)
        {
            int pos1 = a[i];
            int pos2 = b[i];

            int per1 = arr[pos1];
            int per2 = arr[pos2];

            s[per1].insert(pos2);
            s[per2].insert(pos1);

            arr[pos1] = per2;
            arr[pos2] = per1;

        }
    }

    for(int i = 1 ; i <= N ; i++)
    {
        cout << s[i].size()<<"\n";
    }






    // Please write your code here.

    return 0;
}
