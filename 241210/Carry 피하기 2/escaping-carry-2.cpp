#include <iostream>
using namespace std;
int n;
int arr[24];


bool isCarry(int i , int j , int k)
{
    int a = arr[i];
    int b = arr[j];
    int c = arr[k];

    while(a != 0 && b!= 0 && c !=0)
    {
        
        int suba = a%10;
        int subb = b%10;
        int subc = c%10;
        a = a/10;
        b = b/10;
        c = c/10;
        if((suba+subb+subc)>=10) return true;
    }
    return false;
    
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }

    //cout << isCarry(0,1,2)<< endl;
    int mx = -1;
    for(int i = 0 ; i < n-2 ; i++)
    {
        for(int j = i+1 ; j < n-1 ; j++)
        {
            for(int k = j+1 ; k < n ; k++)
            {
                if(!isCarry(i,j,k))
                {
                    int sum = arr[i]+arr[j]+arr[k];
                    mx = max(mx,sum);
                }
            }
        }
    }
    cout << mx;
    return 0;
}