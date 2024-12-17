#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int n;
int a[104][2];

bool isXYpeong(int i, int j, int k)
{
    //x평행 -> y가 2개 같아야 함 
    bool isX = false;
    if(a[i][1] == a[j][1] || a[j][1] == a[k][1] || a[k][1] == a[i][1])
    {
        isX = true;
    }
    //y평행 
    bool isY = false;
    if(a[i][0] == a[j][0] || a[j][0] == a[k][0] || a[k][0] == a[i][0])
    {
        isY = true;
    }
    if(isX && isY) return true;
    else false;

}
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int mx = 0;
    for(int i = 0 ;i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            for(int k = j+1 ; k < n ; k++)
            {
                if(isXYpeong(i,j,k))
                {
                    int s1 = ((a[i][0]* a[j][1]) + (a[j][0] * a[k][1]) + (a[k][0] * a[i][1]));
                    int s2 = ((a[j][0]* a[i][1]) + (a[k][0] * a[j][1]) + (a[i][0] * a[k][1]));
                    mx = max(mx,abs(s1-s2));
                }
            }
        }
    }
    cout << mx;
    return 0;
}