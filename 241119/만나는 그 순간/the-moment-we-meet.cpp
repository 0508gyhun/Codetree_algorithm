#include <iostream>
using namespace std;




int n,m;
int a[1000004];
int b[1000004];
int main() {
    // 여기에 코드를 작성해주세요.


    cin >> n >>m;
    int cur = 0;
    int time = 0;
    for(int i = 0 ; i < n ; i++)
    {   
        char d;
        int t;

        cin >> d>>t;
        
        if(d == 'R')
        {
            for(int j = 0 ; j < t ; j++)
            {
               
                a[time] = cur;
                time++;
                cur++;
            }
        }
        else if( d == 'L')
        {
             for(int j = 0 ; j < t ; j++)
            {
                
                a[time] = cur;
                time++;
                cur--;
            }

        }
    }
    

    
    //  for(int i = 1 ; i <= time ; i++) cout << a[i]<<"  ";    


    cur = 0;
    time = 0;
    for(int i = 0 ; i < m ; i++)
    {   
        char d;
        int t;

        cin >> d>>t;
        
        if(d == 'R')
        {
            for(int j = 0 ; j < t ; j++)
            {
               
                b[time] = cur;
                time++;
                cur++;
            }
        }
        else if( d == 'L')
        {
             for(int j = 0 ; j < t ; j++)
            {
                
                b[time] = cur;
                time++;
                cur--;
            }

        }
    }


    //  cout << endl;
    //  for(int i = 1 ; i <= time ; i++) cout << b[i]<<"  ";    


    int ans = -1;
    //  cout << endl;
    // cout << cur<< endl;
    for(int i = 1 ; i < time ; i++)
    {
        if(a[i] == b[i]){
            ans = i;
            break;
        }
    }    

    cout << ans;




    return 0;
}