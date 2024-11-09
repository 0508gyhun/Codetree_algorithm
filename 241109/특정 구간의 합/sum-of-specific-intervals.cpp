#include <iostream>
using namespace std;

int n , m ;

int from, to ;
int a[100];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >>n >> m ;

    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i]; 
    }
    
    for(int i = 0 ; i < m ; i++)
    {
        cin >> from >> to;
        int sum = 0 ;

        for(int j = from  ; j <= to ; j++)
        {
            sum += a[j-1];
        }
        cout << sum << endl;
    }

    return 0;
}