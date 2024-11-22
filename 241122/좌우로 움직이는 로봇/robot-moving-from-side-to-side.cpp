#include <iostream>
using namespace std;

#define MAX 2000004
int n,m; 
int a[MAX];
int b[MAX];
int main() {

    cin >> n >> m;
    // 여기에 코드를 작성해주세요.
    
    int atime = 1 ;
    for(int i = 0 ; i < n ; i ++)
    {   int t;
        char d;
        cin >> t >> d;
        if(d == 'L')
        {
            while(t--)
            {
                a[atime] = a[atime-1] -1;
                atime++; 
            }
        }
        else if( d == 'R')
        {
            while(t--)
            {
                a[atime] = a[atime-1] + 1;
                atime++; 
            } 
        }
    }

    //cout << atime << endl;
    

    int btime = 1 ;
    for(int i = 0 ; i < m ; i ++)
    {   int t;
        char d;
        cin >> t >> d;
        if(d == 'L')
        {
            while(t--)
            {
                b[btime] = b[btime-1] -1;
                btime++; 
            }
        }
        else if( d == 'R')
        {
            while(t--)
            {
                b[btime] = b[btime-1] + 1;
                btime++; 
            } 
        }
    }

    //cout << btime << endl;
    
    if(atime>btime)
    {
        for(int i = btime ; i < atime ; i++)
        {
            b[i] = b[i-1];
        }
    }
    else
    {
        for(int i = atime ; i < btime ; i++)
        {
            a[i] = a[i-1];
        }
    }
    int cnt = 0;
    int maxtime = 0;
    
    if(atime>btime) maxtime = atime;
    else maxtime = btime;

    for(int i = 1 ; i < maxtime ; i++)
    {
        if(a[i-1] != b[i-1] && a[i] == b[i]) cnt++;
    }

    cout << cnt;
    return 0;
}