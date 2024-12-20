#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >>b >>c;

    int mx = INT_MIN;

    for(int i = 0 ; i *a<= c ; i++)
    {
        int cnt1 = i*a;

        int cnt2= (c-cnt1) / b;

        int sum = cnt1 + (cnt2* b);
        mx = max(mx,sum);

    }

    cout << mx;
    return 0;
}