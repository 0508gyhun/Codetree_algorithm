#include <iostream>
using namespace std;
int n;
int a[101];
int temp[101];


int st, ed,st1,ed1;
int main() {
    // Please write your code here.
    
    cin >> n;

    for(int i = 1 ; i <= n ; i++) // 1-based
    {
        cin >> a[i];
    }

    cin >> st >> ed;
    int idx = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        if((i >= st) && (i <= ed)) continue;
        temp[idx++] = a[i];
    }

    // for(int i = 1 ; i < idx ; i++)
    // {
    //     cout << temp[i] << " ";
    // }
    // cout << endl;
    n = idx;
    cin >> st1 >> ed1;
    idx = 1;

    for(int i = 1 ; i <n  ; i++)
    {
        if((i >= st1) && (i <= ed1)) continue;
        a[idx++] = temp[i];
        
    }
    cout << idx-1<< endl;

    for(int i = 1 ; i < idx ; i++)cout << a[i]<<"\n"; 

    return 0;
}