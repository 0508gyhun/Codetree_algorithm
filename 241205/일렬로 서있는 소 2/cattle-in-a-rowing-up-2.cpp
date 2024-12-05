#include <iostream>
using namespace std;
int n;
int a[104];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int cnt = 0 ; 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            for(int k = j+1 ; k < n ; k++)
            {
                if(i < j && j < k && a[i]<a[j] && a[j] < a[k]) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}