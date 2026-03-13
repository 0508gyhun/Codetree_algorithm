#include <iostream>

using namespace std;

int N;
char matches[100004];
int r[100004];
int l[100004];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> matches[i];
    }
    string rsp = "HSP";
    
    for(int s = 0 ; s < 3 ; s++)
    {
        int cnt = 0;
        char c = rsp[s];
        for(int i = 1 ; i <= N; i++)
        {
            if(matches[i] == c)
            {
                cnt++;
            }
            r[i] = max(r[i],cnt);
        }
    }
    // for(int i = 1 ; i <= N ; i++)
    // {
    //     cout << r[i]<<" ";
    // }
    // cout << endl;

    for(int s = 0 ; s < 3; s++)
    {
        int cnt = 0 ; 
        char c = rsp[s];
        for(int i = N ; i>=1 ; i--)
        {
            if(matches[i] == c)
            {
                cnt++;
            }
            l[i] = max(l[i],cnt);
        }
    }
    // for(int i = 1 ; i <= N ; i++)
    // {
    //     cout << l[i]<<" ";
    // }
    // cout << endl;
    int ans = -1;
    for(int i = 1 ; i < N ;i++)
    {
        // cout << l[i]<<" "<<r[i+1]<< endl;
        ans = max(ans, r[i] + l[i+1]);
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
