#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int a[1004][2];
int tmp[1004];
int n,b;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n >>b;

    int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i][0] >> a[i][1];
        tmp[i] = a[i][0] +a[i][1];
        sum+=tmp[i];
    }

    
    int mx = INT_MIN;
    for(int i = 0 ; i < n ; i ++)
    {
        int tmpsum = 0;
        int cnt = 0;
        int tmp[1004];
        for(int j = 0; j < n; j++) {
            // 현재 학생의 선물만 반값 처리
            if(j == i) {
                tmp[j] = a[j][0]/2 + a[j][1];
            } else {
                tmp[j] = a[j][0] + a[j][1];
            }
        }
        sort(tmp,tmp+n);
        
        for(int j = 0 ; j < n ; j++)
        {        

            if(tmpsum + tmp[j]<=b)
            {
                tmpsum += tmp[j];
                cnt++;
            }

        }
        //tmp[i] = tmp[i]+ a[i][0]/2;
        mx = max(mx,cnt);
    }
    cout << mx;
    return 0;
}