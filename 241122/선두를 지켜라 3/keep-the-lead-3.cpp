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
    for(int i = 0 ; i < m ; i++)
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
   int changes = 0;
    int currentLeader = 0;  // 0: 초기상태, 1: A리더, 2: B리더, 3: 동률
    
    for(int i = 1; i <= acur; i++) {
        int newLeader;
        if(a[i] > b[i]) {
            newLeader = 1;
        }
        else if(a[i] < b[i]) {
            newLeader = 2;
        }
        else {
            newLeader = 3;
        }
        
        if(newLeader != currentLeader) {
            changes++;
            currentLeader = newLeader;
        }
    }
    
    cout << changes;
    return 0;
}