#include <iostream>

using namespace std;

const int MAX_N = 1000;

int N;
int dp[1004];
int M[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < i; j++) {
            
            if(M[j] > M[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0 ;
    for (int i = 0; i < N; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans;


    // Please write your code here.

    return 0;
}
