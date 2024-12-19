#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int x[104];
char c[104];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> t >> a >> b;

    for(int i = 0 ; i < t ; i++)
    {
        cin >> c[i] >> x[i];
    }
    int cnt = 0;
    for(int i = a ; i <= b ; i++)
    {
        int minS = INT_MAX;
        int minN = INT_MAX;
        for(int j = 0 ; j <t ;j++)
        {
            if(c[j] == 'S')
            {
                int distS = abs(x[j]-i);
                minS = min(minS,distS);
            }
            else if ( c[j] == 'N')
            {
                int distN = abs(x[j] - i);
                minN = min(minN,distN);
            }
        }
        if(minS<=minN) cnt++;

    }
    cout << cnt;
    return 0;
}