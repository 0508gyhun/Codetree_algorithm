#include <iostream>

using namespace std;
int n=19;
int a[23][23];

//동 동북 북 북서 서 남서 남 동남
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dx[8] = {1,1,0,-1,-1,-1,0,1};

bool isRange(int y, int x){
    return y>=0 && y < n && x>= 0 && x<n;
}

int main() {

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(a[i][j] == 0) continue;

            for(int k = 0 ; k < 8 ; k++) // dir
            {
                int cury = j;
                int curt=1;
                int curx = i;
                while(1)
                {
                    int ny = cury + dy[k];
                    int nx = curx + dx[k];
                    if(!isRange(ny,nx))break;
                    if(a[i][j] != a[ny][nx]) break;   
                    curt++;
                    curx = nx;
                    cury = ny;
                }
                if(curt == 5)
                {
                    cout << a[i][j] << endl;
					cout << i + 2 * dx[k] + 1 << " " << j + 2 * dy[k] + 1;
					return 0;
                }
             

            }
        }
    }

    cout <<0;
    // 여기에 코드를 작성해주세요.
    return 0;
}