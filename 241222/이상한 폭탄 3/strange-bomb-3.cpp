#include <iostream>
using namespace std;
int n,k;
int a[100];
bool exp[104];

int bomb[1000001];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(j-i >k) break;
            if(a[i] != a[j]) continue;

            if(exp[i] == false)
            {
                bomb[a[i]]++;
                exp[i] = true;
            }

            if(exp[j] == false)
            {
                bomb[a[j]]++;
                exp[j] = true;
            }


        }
    }
    int mxval = 1;
    int mxidx = 0;
    for(int i = 0 ; i <= 1000001 ; i++)
    {
        if(mxval <= bomb[i])
        {
            mxval = bomb[i];
            mxidx = i;
        }
    }
    cout << mxidx;
    return 0;
}