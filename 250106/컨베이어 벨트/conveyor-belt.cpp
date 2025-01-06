#include <iostream>
using namespace std;

int a[204];
int n,t;

int main() {
    // Please write your code here.
    
    cin >> n >> t;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    for(int i = n ; i < 2*n ; i++)
    {
        cin >> a[i];
    }

    //for(int i = 0 ; i < 2*n ; i++) cout << a[i]<<" ";
    for(int k = 0 ; k < t ; k++)
    {
        int tmp= a[2*n-1];
        for(int i = 2*n-1 ; i > 0 ; i--){
            a[i] = a[i-1];        
        }
        a[0] = tmp;

    }
    for(int i = 0 ; i < n ; i++) cout << a[i]<<" ";
    cout << endl;
    for(int i = n ; i < 2*n ; i++) cout << a[i]<<" ";


    
    return 0;
}