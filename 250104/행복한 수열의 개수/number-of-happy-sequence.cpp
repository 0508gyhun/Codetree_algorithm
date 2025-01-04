#include <iostream>
using namespace std;
int n,m;
int a[104][104];

int main() {
    // Please write your code here.

    cin >> n >>m;

    for(int i = 0 ; i< n ; i++)
    {
        for(int j =0 ; j < n ; j++)
        {
            cin >> a[i][j];

        }
    }

   int ans = 0;
    for(int i = 0 ; i< n ; i++)
    {
        bool flag = false;
        int prev = -1;
        int cnt = 1;
        for(int j =0 ; j < n ; j++)
        {
            if(a[i][j] == prev) cnt++; 
            prev = a[i][j];

        }
        if(cnt >= m) ans++; 
    }

  
    for(int i = 0 ; i< n ; i++)
    {
        bool flag = false;
        int prev = -1;
        int cnt = 1;
        for(int j =0 ; j < n ; j++)
        {
            if(a[j][i] == prev) cnt++; 
            prev = a[j][i];

        }
        if(cnt >= m) ans++; 
    }

    cout << ans;
    return 0;
}