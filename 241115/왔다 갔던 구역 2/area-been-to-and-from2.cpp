#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int num,n;
char dir;

int aR[1000];
int aL[1000];
int main() {


    cin >> n ; 

    int st = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> num >> dir;
        
        if(dir == 'R')
        {
            for(int j = st ; j < st+num ; j++)
            {
                if(j >= 0)
                {
                    aR[j]++;
                }
                else
                {
                    aL[-j]++;
                }
            }
            st = st+num+1;
        }
        else if ( dir == 'L')
        {
             for(int j = st ; j > st-num ; j--)
            {
                if(j >= 0)
                {
                    aR[j]++;
                }
                else
                {
                    aL[-j]++;
                }
            }
            st = st-num-1;
        }

    }
    int cnt = 0 ;
    for(int i = 0 ; i < 1000 ; i++)
    {
        if(aR[i] >= 2) cnt++;
        
    }
   

    for(int i = 1 ; i < 1000 ; i++)
    {
       if(aL[i] >= 2) cnt++;
    }
    cout << cnt ;
    // 여기에 코드를 작성해주세요.
    return 0;
}