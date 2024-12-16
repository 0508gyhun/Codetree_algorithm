#include <iostream>
using namespace std;
#include <bits/stdc++.h>



int a[6];

int sol(int i,int j, int p, int k)
{
    //cout << i <<" "<<j<<" "<<p<<" "<<k<< endl;
    int sum = 0 ;
    for(int i = 0 ; i < 5 ; i++)
    {
        sum+=a[i];
    } 
    int tmp1 = (a[i]+a[j]);
    int tmp2 = a[p]+a[k];
    int tmp3 = sum-(tmp1+tmp2);
    int ans = INT_MAX;
   // cout << "tmp1"<<" "<<tmp1<<" tmp2 "<<tmp2<<" tmp3 "<< tmp3<<endl;
    
    if(tmp1 != tmp2 && tmp2!= tmp3 && tmp3!= tmp1)
    {
        //cout << i<<" "<<j<<" "<<p<<" "<<k<< endl;
        int ret = (tmp1);
        ret = min(ret, tmp2);
        ret = min(ret, tmp3);
        //cout <<"min "<< ret;

        int ret2 = abs(tmp1);
        ret2 = max(ret2, (tmp2));
        ret2 = max(ret2, abs(tmp3));
        //cout <<"max "<< ret2;


        //cout << "ans" << " "<< abs(ret-ret2)<< endl;
        ans = min(ans,abs(ret-ret2));
        
        return ans;
    }
    else
    {
        return INT_MAX;
    }

}


int main() {
    // 여기에 코드를 작성해주세요.

for(int i = 0 ; i < 5 ; i++) cin >> a[i];


int mn = INT_MAX;
for(int i = 0 ; i < 5 ; i++)
{
    for(int j = i+1 ; j < 5 ; j++)
    {

        for(int p = 0 ; p < 5 ; p++)
        {
            for(int k = p+1 ; k < 5 ; k++){
                if( i== p || i==k|| j ==p || j==k) continue;
                
                mn = min(mn,sol(i,j,p,k));
            }
        }

    }
}

cout << mn;
    return 0;
}