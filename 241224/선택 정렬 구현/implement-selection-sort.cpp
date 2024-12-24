#include <iostream>
using namespace std;
int n;
int a[104];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ; 
    }

    for(int i = 0 ; i < n ; i++)
    {
        int mnidx = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(a[mnidx] > a[j])
            {
                mnidx = j;
            }
        }
        swap(a[mnidx],a[i]);

    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << a[i]<<" ";
    }
    
    return 0;
}