#include <iostream>
using namespace std;

int n, m, r, c;
char directions[10000];
int a[101][101];
//왼 오 위 아래
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int main() {
    cin >> n >> m >> r >> c;
    
    for (int i = 0; i < m; i++) {
        cin >> directions[i];
    }
    
    r--; c--;
    int top = 1;
    int mark = 6;
    int right = 3;
    int left = 4;
    int front = 2;
    int back = 5;
    
    int y = r;
    int x = c;
    int sum = 0;
    
    a[r][c] = mark;
    sum += mark;
    // cout << mark << endl;
    
    for(int i = 0; i < m; i++) {
        int ny = y, nx = x;
        int new_top = top;
        int new_mark = mark;
        int new_right = right;
        int new_left = left;
        int new_front = front;
        int new_back = back;
        
        if (directions[i] == 'L') {
            ny = y + dy[0];
            nx = x + dx[0];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            new_top = right;
            new_mark = left;
            new_right = mark;
            new_left = top;
        }
        else if (directions[i] == 'R') {
            ny = y + dy[1];
            nx = x + dx[1];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            new_top = left;
            new_mark = right;
            new_right = top;
            new_left = mark;
        }
        else if (directions[i] == 'U') {
            ny = y + dy[2];
            nx = x + dx[2];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            new_top = front;
            new_mark = back;
            new_front = mark;
            new_back = top;
        }
        else if (directions[i] == 'D') {
            ny = y + dy[3];
            nx = x + dx[3];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            new_top = back;
            new_mark = front;
            new_front = top;
            new_back = mark;
        }
        
        // 이동이 가능한 경우에만 상태 업데이트
        y = ny;
        x = nx;
        
        

        top = new_top;
        mark = new_mark;
        right = new_right;
        left = new_left;
        front = new_front;
        back = new_back;
        
        a[y][x] = mark;
       // sum += mark;
    //   
    }
    int ans = 0;
    // cout << endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(a[i][j] != 0)
            {
                 ans+= a[i][j];
                //  cout << a[i][j] <<" ";
            }
        }
    }

    cout << ans;
    return 0;
}