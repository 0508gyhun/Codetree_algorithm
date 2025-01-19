#include <iostream>

using namespace std;

int n;
int a[100][100];
int visited[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int cnt;

void dfs(int y, int x, int target)
{
    for(int i = 0 ; i <4 ; i++)
    {
        int ny = y+ dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx <0 || ny>=n || nx >= n || visited[ny][nx] == 1 || a[ny][nx] != target) continue;
        visited[ny][nx] = 1;
        cnt++;
        dfs(ny,nx,target);
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int block_cnt=0;
    int mx = -1;
    int key = 0;
    bool flag = 0;
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt = 1;
            int target =a[i][j];
            if(visited[i][j] == 0 && a[i][j] >= 1){
                visited[i][j] = 1;
                dfs(i,j,target);
                //cout << cnt<< endl;
                if(cnt>=4)
                {
                    block_cnt++;
                    
                }
                if(mx< cnt)
                {
                    mx = cnt;
                    key = a[i][j];
                }
               

            }

        }
    }
    cout << block_cnt <<" "<<mx;

    // Write your code here!

    return 0;
}
