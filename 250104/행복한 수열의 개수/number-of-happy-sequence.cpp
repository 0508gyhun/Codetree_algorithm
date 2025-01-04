#include <iostream>
using namespace std;
int n,m;
int a[104][104];
int seq[104];
bool isgood()
{
    int prev = -1;
    int mxcnt = 1;
    int cnt = 1 ;
    for(int i = 0 ; i <n; i++)
    {
        if(prev == seq[i]) cnt++;
        else
        {
            cnt = 1;
        }
        mxcnt = max(mxcnt ,cnt);
        
        prev = seq[i];
    }
    return mxcnt>= m;

}

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
       
        for(int j =0 ; j < n ; j++)
        {
            seq[j] = a[i][j];
        }
        if(isgood())
        {
            ans++;
        }
    }

  
 
    for(int i = 0 ; i< n ; i++)
    {
       
        for(int j =0 ; j < n ; j++)
        {
            seq[j] = a[j][i];
        }
        if(isgood())
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}