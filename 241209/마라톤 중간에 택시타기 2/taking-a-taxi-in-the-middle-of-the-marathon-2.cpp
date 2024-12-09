#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        int x;
        int y;

    A(int x , int y)
    {
        this->x = x;
        this->y = y;
    }
    A(){
        
    }
};
A a[104];

int n ;
int x,y;

int main() {
    // 여기에 코드를 작성해주세요.



    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x >> y;
        a[i].x =x;
        a[i].y = y;

    }

    int mn = INT_MAX;
    int tmp = 0 ;
    for(int j = 2 ; j < n ; j++)
    {
        int sum = 0;
        int prev = 1;
        for(int i = 2; i <= n ; i++)
        {
            if(i == j){
                continue;
            }
            tmp = abs(a[i].x - a[prev].x)+ abs(a[i].y - a[prev].y);
            prev = i;
            sum+=tmp;
            
        }
        mn = min(mn,sum);


    }
    cout << mn;
    
    return 0;
}