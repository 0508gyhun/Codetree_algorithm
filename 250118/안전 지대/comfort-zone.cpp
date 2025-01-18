#include <iostream>

using namespace std;

int n,m;
int a[50][50];
int temp[50][50];
int visited[50][50];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y+ dy[i] ; 
        int nx = x + dx[i] ;
        if(ny<0 || ny >= n || nx <0 || nx >= m || visited[ny][nx] == 1 || a[ny][nx] ==0) continue;

        visited[ny][nx] = 1;
        dfs(ny,nx); 

    }
}

int main() {
    cin >> n >> m;
    int num_mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            temp[i][j] = a[i][j];
            num_mx = max(num_mx,a[i][j]);
        }
    }
    //cout << num_mx;
    int mx = 0;
    int key;
    int cnt;
    // k = 1~젤 큰수 // 0은 웅덩이 
    for(int k = 1 ; k <= num_mx ; k++)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = a[i][j];
            }
        } // initiallize

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;
            }
        } //visit init

            

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(a[i][j] <=k) a[i][j] = 0;
            }
        } // make dumb
        cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(a[i][j] >=1 && visited[i][j] == 0)
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        } 
        //  cout <<"k"<<" "<<k<<" "<<cnt<< endl;// calculate safe
        if(mx<cnt)
        {
            mx = cnt;
            key = k;
        }
          
    }
    cout <<key<<" "<<mx;
    // Write your code here!

    return 0;
}
