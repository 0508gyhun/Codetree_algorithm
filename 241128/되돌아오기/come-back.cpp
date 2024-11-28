#include <iostream>
using namespace std;
//            eswn
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int n;

int getdir(char c){
    if(c == 'N') return 3;
    else if(c=='E') return 0;
    else if (c == 'W') return 2;
    else if(c == 'S') return 1;
}
int num ;
char c ;
int main() {

    cin >> n;
    
    int x = 0 ;
    int y = 0 ;
    int ans = 0;
    int flag = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> c >> num;
        int dir = getdir(c);

        for(int j = 0 ; j < num ; j ++)
        {
            
            //cout <<ans<< " "<< y<<" "<< x << endl;
            int ny = y+ dy[dir];
            int nx = x+ dx[dir];

            if(ny == 0 && nx == 0){
                flag =1;
                ans++;
                cout<< ans;
                return 0;
            }
            ans++;
            x = nx;
            y = ny;


        }
    }

    if(flag)cout << ans << endl;
    else cout << -1;
    // 여기에 코드를 작성해주세요.
    return 0;
}