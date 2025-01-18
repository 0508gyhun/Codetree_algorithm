#include <iostream>

using namespace std;
int cnt; 
int n, m;
int from[10000], to[10000];
int a[1000][1000];
int visited[1000];
void dfs(int vertex)
{
    for(int i= 1 ; i <= n; i++)
    {
        if(a[vertex][i] == 1 && visited[i] == 0 )
        {
            //cout <<i <<endl;
            visited[i] = 1;
            cnt++;
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        a[from][to] = 1;
        a[to][from]=1;
    }

    visited[1] = 1;

    dfs(1);
    // Write your code here!
    cout << cnt;

    return 0;
}
