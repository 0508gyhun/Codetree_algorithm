#include <iostream>

using namespace std;

int n, m;
int arr[200][200];
int temp[200][200];

// void bomb(int r, int c)
// {
//     int num = a[r][c];

//     // int y = r;
//     // int x = c;

//     int k = a[r][c];
//     a[r][c] = 0;
//     for(int i = 0 ; i < 4 ; i++)
//     {
//         int y = r;
//         int x = c;
//         for(int j = 1 ; j < k ; j++)
//         {
//             int ny = y+ dy[i];
//             int nx = x+ dx[i];
//             if(ny<0 || nx <0 || ny>=n || nx >=n)continue;
//            // cout << "ny nx" <<ny<<" "<<nx<< endl;
//             a[ny][nx] = 0;
//             y = ny;
//             x = nx;
//         }
        
//     }

// }

void bomb(int r, int c, int k)
{
    arr[r][c] = 0;

    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};

    for(int i = 0 ; i < 4 ; i++)
    {
        int y = r;
        int x = c;
        for(int j = 1 ; j < k ; j++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx <0 || nx >=n || ny >= n) break;
            // cout << "ny "<<ny <<" nx"<< nx << endl;
            arr[ny][nx] = 0;
            y = ny;
            x = nx;
        }
    }

}

void print()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void down ()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++){
            temp[i][j] = 0;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        int idx = n-1;
        for(int j = n-1 ; j >= 0 ; j--)
        {
            if(arr[j][i] != 0 ) temp[idx--][i] = arr[j][i];
        }
    }
    // cout << "ans"<< endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++){
            cout << temp[i][j] <<" ";;
        }
        cout << endl;
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        target--;

        // int r = 0 ;
        // int c = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if( arr[j][target] != 0 )
            {
                // cout << j <<" "<<target << " "<< arr[j][target] << endl;
                bomb(j, target , arr[j][target]);
                break;
            }
        }

    //    print();
        //c열에서 0 이 아닌 가장 맨위 숫자만큼 십자가로 터트리기
        // 0인 것 다 중력으로 내리기 
        //2차원 배열 초기화 조심.
        
    }

    down();

    // Write your code here!

    return 0;
}
