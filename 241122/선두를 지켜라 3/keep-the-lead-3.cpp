#include <iostream>
using namespace std;

int a[1000004];
int b[1000004];
int n,m;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>> m;

    int acur = 1;
    for(int i = 0 ; i < n ; i++)
    {
        int v,t;
        cin >> v>>t;
        while(t--)
        {
            a[acur] = a[acur-1]+v;
            acur++;
        }
    }

    // for(int i = 0 ; i < acur ; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "acur"<<acur << endl;


    int bcur = 1;
    for(int i = 0 ; i < n ; i++)
    {
        int v,t;
        cin >> v>>t;
        while(t--)
        {
            b[bcur] = b[bcur-1]+v;
            bcur++;
        }
    }
    // cout << endl;
    // for(int i = 0 ; i < bcur ; i++)
    // {
    //     cout << b[i] << " ";
    // }

    // cout << "bcur"<<bcur << endl;
    int mmx = 0;
    if(acur>bcur) mmx = acur;
    else mmx = bcur;

    // if(acur>bcur)
    // {
    //     for(int i = bcur ; i < acur ; i++)
    //     {
    //         a[i] = a[i-1];
    //     }
    // }
    // else{
    //     for(int i = acur ; i < bcur ; i++)
    //     {
    //         b[i] = b[i-1];
    //     }
    // }

    // a=1,b=2,ab=3;
    int cnt = 0 ;
    int leader = 0 ;
    for(int i = 1 ; i < mmx ; i++)
    {
        if(a[i] > b[i]){
            if(leader != 1) {
                cnt++;
              //  cout << i << endl;
            }
            leader = 1;
        }
        else if( a[i] < b[i])
        {
            if(leader != 2) {
                cnt++;
              //  cout << i << endl;
            }
            leader = 2;
        }
        else if ( a[i] == b[i])
        {
            if(leader != 3) {
                cnt++;
              //  cout << i << endl;
            }
            leader =3;
        }
    }
    cout << cnt;
    return 0;
}