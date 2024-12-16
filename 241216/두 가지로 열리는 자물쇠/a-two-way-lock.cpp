#include <iostream>
using namespace std;
int n;

int sub1;
int sub2;
int a,b,c,d,e,f;

bool One(int i, int j, int k)
{
    int tmp1 = min((a-i),(i-a));
    if(tmp1<0) tmp1 = tmp1+n;

    if(tmp1>2) return false;


}


int main() {
    

    cin >> n;
    
    cin >> a >> b >> c;
    cin >> d>> e >>f;


    int cnt = 0;
    for(int i = 1 ;i <= n; i++)
    {
        for(int j = 1 ; j <= n; j++)
        {
            for(int k = 1; k<= n ;k++)
            {
                if((2 >= abs(a-i) || n-abs(a-i) <= 2) && (abs(b-j)<= 2 || n- abs(b-j)<=2) &&(abs(c-k)<= 2 || n- abs(c-k)<=2)) cnt++;
                else if((2 >= abs(d-i) || n-abs(d-i) <= 2) && (abs(e-j)<= 2 || n- abs(e-j)<=2) &&(abs(f-k)<= 2 || n- abs(f-k)<=2)) cnt++;
                
            }
        }
    }
    cout << cnt;
    return 0;
}