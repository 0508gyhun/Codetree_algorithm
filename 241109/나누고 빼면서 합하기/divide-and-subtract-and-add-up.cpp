#include <iostream>
using namespace std;

int n , m;

int arr[100];

int main() {

    cin >> n >> m ;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i]; 
    }

    int sum = 0;
    
    while(m>=1)
    {
        //cout << m << " ";
        sum += arr[m-1];
        if(m % 2 == 0)
        {
            m = m/2;
        }
        else
        {
            m = m -1;
        }
        
    }
    cout << sum;

    // 여기에 코드를 작성해주세요.
    return 0;
}
//2