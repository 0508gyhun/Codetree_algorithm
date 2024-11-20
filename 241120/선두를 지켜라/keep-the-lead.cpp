#include <iostream>
using namespace std;
int n,m;
int a[1000004];
int b[1000004];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >>m;

    int cur=0;
    for(int i = 0 ; i < n ;i++)
    {
        int v,t;
        cin >> v >>t;
        
        while(t--)
        {
            a[cur+1] = a[cur] + v;
            cur++;
        }
    }

    // for(int i = 0 ; i < 100 ; i++)
    // {
    //     cout << a[i]<<" ";
    // }
    // cout << endl;

    cur=0;
    for(int i = 0 ; i < n ;i++)
    {
        int v,t;
        cin >> v >>t;
        
        while(t--)
        {
            b[cur+1] = b[cur] + v;
            cur++;
        }
    }
    int leader = 0;
    int ans = 0 ;
    for(int i = 1 ; i < 1000004 ; i++)
    {
        if(a[i]>b[i]){
            if(leader == 2) ans++;

            leader=1;
        }
        else if(a[i]<b[i]){
            if(leader ==1) ans++;
            leader=2;
        }

    }

    cout << ans;
    return 0;
}