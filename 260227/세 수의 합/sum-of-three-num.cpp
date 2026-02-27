#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 입출력 속도 향상 (C++ 알고리즘 풀이 시 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long total_count = 0; // 경우의 수가 매우 커질 수 있으므로 long long 사용

    // 1. 첫 번째 숫자를 고정합니다.
    for (int i = 0; i < n; i++) {
        int target = k - arr[i]; // 나머지 두 수의 합 목표치
        
        // 2. 지나온 숫자의 빈도수를 기록할 해시맵 (장부)
        unordered_map<int, int> history;
        
        // 3. i번 위치 뒤에 있는 숫자들을 탐색하며 2개를 마저 고릅니다.
        for (int j = i + 1; j < n; j++) {
            int needed = target - arr[j]; // target을 만들기 위해 필요한 짝꿍 숫자
            
            // 장부에 짝꿍 숫자가 기록되어 있는지 확인
            // C++에서는 count() 함수로 키(key)의 존재 여부를 알 수 있습니다.
            if (history.count(needed) > 0) {
                total_count += history[needed]; // 찾았다면 그 개수만큼 정답에 더함
            }
            
            // 현재 숫자 arr[j]도 다음 탐색을 위해 장부에 기록
            // C++의 map은 없는 키에 접근해 ++를 하면 자동으로 1로 초기화해 줍니다.
            history[arr[j]]++;
        }
    }

    cout << total_count << "\n";

    return 0;
}