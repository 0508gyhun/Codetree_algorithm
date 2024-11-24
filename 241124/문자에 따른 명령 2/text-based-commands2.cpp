#include <iostream>
using namespace std;


int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
string s;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    int dir = 3;
    int x = 0;
    int y = 0;
    int ny=0;
    int nx = 0 ;

    for(int i = 0 ;i< s.size() ; i++)
    {
        if(s[i] == 'L')
        {
            dir = (dir-1+4)%4;
        }
        else if( s[i] == 'R')
        {
            dir = (dir+1)%4;
        }
        else if( s[i] == 'F')
        {
            y = y+ dy[i];
            x = x+ dx[i];
        }
    }
    cout << y<< " "<< x;
    
    
    return 0;

}