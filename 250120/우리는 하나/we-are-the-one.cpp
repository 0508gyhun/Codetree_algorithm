#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> v;

int n, k, u, d;
int a[8][8];
int visited[8][8];

int nums[100];
queue <pair<int, int>> q;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int cnt;

int mx = -1;

void initvisited()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            visited[i][j] = 0;
        }
    }
}
bool ispossible(int y, int x , int ny , int nx)
{
    if(abs(a[ny][nx] - a[y][x]) >= u && abs(a[ny][nx] - a[y][x]) <=d) return true;
    return false;
}

void bfs()
{
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny <0 || nx>=n || ny>=n ||!ispossible(y,x,ny,nx) || visited[ny][nx] ==1) continue;
             //cout << "ny" << ny<<"nx"<<nx<<endl;
            visited[ny][nx] = 1;
            cnt++;
            q.push({ny,nx});
        }
    }
}
void print()
{
    initvisited();
    
    for(int i : v )
    {
        int r = i/n;
        int c = i%n;
        //   cout << r <<" "<< c<< endl;;
        q.push({r,c});
        visited[r][c]=1;

    }
    //  cout<<endl;
    cnt=k;
    bfs();
    //   cout<<"cnt"<<" "<<cnt<<endl;
    mx = max(mx,cnt);
    
    
    return ;
}

void sol(int idx, int cnt)
{
    if(cnt == k)
    {
       print();
       return;
    }
    if(idx == n*n)
    {
        return;
    }

    v.push_back(idx);
    sol(idx+1,cnt+1);
    v.pop_back();

    sol(idx+1,cnt);

}


int main() {
    cin >> n >> k >> u >> d;
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            nums[c++] = a[i][j];
        }
    }

    sol(0,0);
//o x n6n k 
    // Write your code here!
    cout << mx;
    return 0;
}
