#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int n;
int a[104][2];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
       for(int j = 0 ; j < 2; j++)
       {
            cin >> a[i][j];
       }
    }

    int sqmn = INT_MAX;

    for(int i = 0 ; i < n ; i++)
    {

        int mnx = INT_MAX;
        int mny = INT_MAX;

        int mxx = INT_MIN;
        int mxy = INT_MIN;

       for(int j = 0 ; j < n; j++)
       {
            if(i == j) continue;
            
            mnx = min(mnx,a[j][0]);
            mny = min(mny,a[j][1]);

            mxx = max(mxx,a[j][0]);
            mxy = max(mxy,a[j][1]);


       }
        int sq = (mxx-mnx) * (mxy-mny);
       // cout << "i "<<i<<" "<< sq<< endl;
        sqmn = min(sqmn,sq);

    }

    cout << sqmn;
    // for(int i = 0 ; i < n ; i++)
    // {
    //    for(int j = 0 ; j < 2; j++)
    //    {
    //         cout << a[i][j]<<" ";
    //    }
    //     cout << endl;
    // }
    return 0;
}