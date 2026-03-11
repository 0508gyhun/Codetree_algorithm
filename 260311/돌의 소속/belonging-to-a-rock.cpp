#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, Q;
int arr[4][100004];
int psum[4][100004];

void getSum(int s, int e)
{
    for(int i = 1 ; i <= 3; i++)
    {
        cout << psum[i][e] - psum[i][s-1]<<" ";
    }
    cout << endl;
}

int main() {
    cin >> N >> Q;


    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp][i]++;
    }

    //psum 만들기
    for(int i = 1 ; i <= 3 ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            psum[i][j] = psum[i][j-1] + arr[i][j];
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        getSum(a,b);
    }

    // Please write your code here.

    return 0;
}
