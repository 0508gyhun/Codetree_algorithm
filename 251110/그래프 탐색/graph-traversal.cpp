#include <iostream>

using namespace std;

int n, m;
int from[10000], to[10000];
int a[10004][10004];
int visited[10004];
int cnt = 0 ;


void dfs(int i) {
    visited[i] = 1;
    
    for(int j = 1 ; j <= n ; j ++) {
        if(visited[j] == 0 && a[i][j] == 1 ) {
            visited[j] = 1;
            cnt++;
            dfs(j);
        }
    }
}

int main() {
    cin >> n >> m; // 정점 , 간선


    for (int i = 0; i < m; i++) {
        int f;
        int t;
        cin >> f >>t;
        a[t][f] = 1;
        a[f][t] = 1;
    }
    
    dfs(1);
    // for(int i = 1; i <= n ;i++) {
    //     for(int j = 1 ; j <= n ; j++)
    //     {
    //         if(visited[i][j] == 0 && a[i][j] == 1) {
    //             dfs(i,j);
    //         }

    //     }
    // }
    cout << cnt;
    // Please write your code here.

    return 0;
}
