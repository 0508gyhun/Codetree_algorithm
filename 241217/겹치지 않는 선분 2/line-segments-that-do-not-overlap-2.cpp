#include <iostream>
using namespace std;


int a[104][2];
int n;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 
    for(int i= 0 ; i < n ; i++)
    {
        cin >> a[i][0]>>a[i][1];


    }
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        bool over = false;
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j) continue;

            if((a[i][0] > a[j][0] && a[i][1] < a[j][1]) || (a[i][0] < a[j][0] && a[i][1]>a[j][1]))
            {
                over = true;
            }

        }
        if(!over) cnt++;
    }
    cout << cnt;
    return 0;
}