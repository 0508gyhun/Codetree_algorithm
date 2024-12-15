#include <iostream>
using namespace std;


int n,m;
int arr1[104];
imt arr2[104];


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >>m;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
	for(int i = 0; i < m; i++)
        cin >> arr2[i];
    sort(arr2,arr2+m);

    for(int i = 0 ; i <= n-m ; i++)
    {
        for(int j = 0 ; j < m; ; j ++)
        {
            tmp[j] = arr1[i+j];
        }
        sort(tmp , tmp+m);
        bool issame = true;
        for(int j = 0 ; j < m ; j++)
        {
            i(arr2[j] != tmp[j])i{
                issame = false;
                break;
        }
        if(issame) cnt++;
    }

    cout << cnt;
    return 0;


}