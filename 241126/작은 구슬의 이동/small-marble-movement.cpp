#include <iostream>
using namespace std;

int r,c;
char d;
int n, t; // r d u l
int dy[4] = {0,-1,1,0};
int dx[4] = {1,0,0,-1};

int getNum(char d)
{
    if(d == 'L') return 3;
    else if( d == 'R') return 0;
    else if (d == 'D') return 2;
    else if (d == 'U') return 1;
}


int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n >>t ; 
    cin >> r >> c >>d;
    // cout << "d "<<d<<endl;

    int dir = getNum(d);
    // cout << "dir " << dir<<endl;

    int y = r-1;
    int x = c-1;

     cout << y << " "<< x<<endl;
   
    
    for(int i = 0 ; i < t ; i++)
    {   
        

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0 || ny >= n || nx <0 || nx>= n){
            dir = 3-dir;
            continue;
        }
        y = ny;
        x = nx;
        cout <<i<<" "<< y << " "<< x<<endl;
    }
     cout << y+1 <<" "<< x+1 << endl;
        
    // }
    //     else if(d == 'U')
    //     {

    //     }
    //     else if(d == 'R')
    //     {

    //     }
    //     elseif(d == 'D')
   
    
    // for(int i = 0 ; i < n ; i ++)
    // {
    //     for(int j = 0 ; j < n ; j ++)
    //     {
    //         if(i==r)
    //     }
    // }
    return 0;
}