#include <iostream>
using namespace std;

int n;
int a[1004];
int asum[1003];

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;
    for(int i = 0 ; i < n-1 ; i++)
    {
        cin >> asum[i]; // 4 5 7 6
    }
 // a[0] = 1 , a[1]= 3 a[2] = 
    for(int i = 1 ; i <= n ; i++ ) // 초기 값 경우의 수
    {
        a[0] = i;
        for(int j = 1 ; j <n ; j++)
        {
            a[j] = asum[j-1] - a[j-1];
        }

        // 0- n 의 범위인지, 겹치는거 있는지
        bool flg = true;
        bool cnt[1004] = {0,};
        
        for(int j = 0 ; j < n ; j++)
        {
            if(a[j]<=0 || a[j] > n) flg = false;
            else{
                if(cnt[a[j]]) flg = false;
                cnt[a[j]] = true;
                
            }
        }
        if(flg)
        {
            for(int i = 0 ; i < n ; i++)
            {
                cout << a[i]<<" ";
                
            } 
            return 0;
        }

    }    
    return 0;
}