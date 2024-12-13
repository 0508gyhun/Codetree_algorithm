#include <iostream>
using namespace std;
int n;
int arr[104];
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++)
        {
            int sum = 0;
            for(int k = i ; k <= j ; k ++)
            {
                
                sum += arr[k];
            }
            double av  = (double)sum/(j-i+1);
            for(int k = i ; k <= j ; k ++)
            {
                if( av == arr[k]){
                    cnt++;
                    break;
                }

            }

        }
    }
    cout << cnt;
    return 0;
}