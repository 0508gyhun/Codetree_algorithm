#include <iostream>
using namespace std;
//         동 서 남 북
int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1};

//북 <-> 서
//동->남

int n;
string s;
int target;
char a[1004][1004];
int x,y,sht;
int move_dir,next_dir;
int dir;
void init(int target){

    if(target<=n) {
        dir = 0;
        y = 0;
        x = target-1;            
    }
    else if(n+1 <= target && target<= 2*n)
    {
        dir =1;
        y = target-n-1;
        x = n-1;  

    } 
    else if(2*n+1 <= target&& target<= 3*n) 
    {
        dir =2;
        y = n-1;
        x = n-(target-(2*n));  
    
    }
    else {
        dir = 3;
        y = n-(target-3*n);
        x = 0;  
    }
}
void move(int next_dir){

    x+=dx[next_dir];
    y+=dy[next_dir];

    dir = next_dir;
}
bool isRancge(int y, int x)
{
    if(y>=0 && y<n&& x>=0 && x<n) return true;
    return false;

}


int simul(){
    int ans = 0 ;
    while(isRancge(y,x))
    {
        if(a[y][x] == '/') move(dir^1);
        else move(3-dir);

        ans++;
    }
    return ans;
}



int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int i = 0 ; i <n ; i++)
    {
        // cin >>s;
        {
            for(int j = 0 ; j < n ; j++)
            {
                cin >> a[i][j];
            }
            //cout << endl;
        }
    }
    cin >> target;
    init(target);

    int ans = simul();
   
    

    cout <<ans;
    return 0;
}