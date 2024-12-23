#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(2*n + 1);  // 1-based indexing
    for(int i = 1; i <= 2*n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin() + 1, arr.end());  // 1부터 정렬 (0번 인덱스는 무시)
    
    int min_diff = INT_MAX;
    for(int i = 1; i <= n; i++) {
        min_diff = min(min_diff, arr[n + i] - arr[i]);
    }
    
    cout << min_diff;
    return 0;
}