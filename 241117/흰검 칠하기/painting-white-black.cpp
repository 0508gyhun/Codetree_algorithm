#include <iostream>
using namespace std;

int n ; 

int a[200004];

int cnt_w[200004];
int cnt_b[200004];

int b,w,g;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ;

    int cur = 100000;
    for(int i = 0 ; i < n ; i++)
    {
        int num;
        char dir;
        cin >> num >> dir;
        if(dir == 'L')
        {
            for(int j = 0 ; j < num ; j++)
            {
                a[cur] = 1;
                cnt_w[cur]++;
               // cout << cur <<" ";
                if( j != num-1)cur-- ;
              
            }
        }
        else if ( dir == 'R')
        {
            for(int j = 0 ; j < num ; j++)
            {
                a[cur] = 2;
                cnt_b[cur]++;
               // cout << cur <<" ";
                if(j != num-1) cur++;
                
            }
        }
    }
    for(int i = 0 ; i < 200004 ; i++)
    {
        if(cnt_b[i]>=2 && cnt_w[i] >=2)g++;
        else if(a[i] == 1 ) w++;
        else if(a[i] == 2) b++; 
    }


    cout << w <<" "<<b<<" "<<g;
    return 0;
}