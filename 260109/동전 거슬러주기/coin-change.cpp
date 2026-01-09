#include <iostream>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h> // 실전에서는 써도 되지만, 필요한 헤더만 쓰는 습관이 좋습니다.

using namespace std;

int N, M;
int coin[105];
int dp[100005]; // 3. 배열 크기를 넉넉하게 수정 (문제의 M 최대값 확인 필요)

#define INF 100000000 // 오버플로우 방지를 위한 적당히 큰 값

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    // 1. 초기화: INF로 초기화 (INT_MAX 사용 시 +1 하면 오버플로우 발생)
    for(int i = 1 ; i <= M ; i++) // i <= M 조건 채워넣기
    {
        dp[i] = INF;
    }
    dp[0] = 0;

    for(int i = 1 ; i <= M ; i++)
    {
        for(int j = 0 ; j < N ; j++) 
        {
            if(i - coin[j] >= 0) {
                // 2. 이전 값을 만들 수 없는 경우(INF)에는 갱신하지 않음 (또는 INF가 적당히 작다면 그냥 진행해도 됨)
                // INF를 1억 정도로 잡았으므로 +1 해도 오버플로우 안 남
                dp[i] = min(dp[i], dp[i-coin[j]] + 1);
            }
        }
    }

    if(dp[M] == INF) cout << -1;
    else cout << dp[M];

    return 0;
}