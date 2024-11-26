#include <iostream>
using namespace std;

int r,c; 
char d; 
int n, t; 
int dy[4] = {0,-1,1,0}; 
int dx[4] = {1,0,0,-1};  

int getNum(char d) {     
    if(d == 'L') return 3;     
    else if(d == 'R') return 0;     
    else if(d == 'U') return 1;     
    else if(d == 'D') return 2; 
}   

int main() {     
    cin >> n >> t;      
    cin >> r >> c >> d;     

    int dir = getNum(d);     
    int y = r-1;     
    int x = c-1;       

    for(int i = 0 ; i < t ; i++) {                      
        int ny = y + dy[dir];         
        int nx = x + dx[dir];         

        if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
            dir = (dir + 2) % 4;  // 180도 방향 전환
            continue;
        }         
        y = ny;         
        x = nx;     
    }      

    cout << y+1 << " " << x+1 << endl;     
    return 0; 
}