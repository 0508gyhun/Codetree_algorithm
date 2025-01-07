#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
int r,c,m1,m2,m3,m4;
int dir;
// / 행의 원소를 왼쪽으로 이동
// void moveleft(int idx) {
//     int temp = a[idx][0];
//     for (int i = 0; i < m - 1; i++) {
//         a[idx][i] = a[idx][i + 1];
//     }
//     a[idx][m - 1] = temp;
// }

// // 행의 원소를 오른쪽으로 이동
// void moveright(int idx) {
//     int temp = a[idx][m - 1];
//     for (int i = m - 1; i > 0; i--) {
//         a[idx][i] = a[idx][i - 1];
//     }
//     a[idx][0] = temp;
// }
void sol( int r , int c, int m1, int m2, int m3, int m4, int dir)
{
    int dy[4] = {-1,-1,1,1};
    int dx[4] = {1,-1,-1,1};
    int dr[4] = {m1,m2,m3,m4};

    int str = r;
    int stc = c;
    vector <int> v;
    v.push_back(a[r][c]);
    for(int i = 0 ; i < 4. ; i++){
        for(int j = 0 ; j < dr[i] ; j++)
        {
            r = r + dy[i];
            c = c + dx[i];
            v.push_back(a[r][c]);
        }
    }
    v.pop_back();


    // for(int i : v)
    // {
    //     cout << i<< " ";
    // }
    cout << endl;

    if(dir == 0){ //오른쪽으로 밀어
        int temp = v[v.size()-1];
        for(int i = v.size()-1 ; i>0 ; i--)
        {
            v[i] = v[i-1];
        }
        v[0] = temp;

        // for(int i : v)
        // {
        //     cout << i<< " ";
        // }
        // cout << endl;
    } // 왼쪽으로 밀어 
    else if(dir == 1){
        int temp = v[0];
        for(int i = 0 ; i<v.size()-1 ; i++)
        {
            v[i] = v[i+1];
        }

        v[v.size()-1] = temp;

        // for(int i : v)
        // {
        //     cout << i<< " ";
        // }
        // cout << endl;
    }


// int dy[4] = {-1,-1,1,1};
//     int dx[4] = {1,-1,-1,1};
//     int dr[4] = {m1,m2,m3,m4};

//     vector <int> v;
//     v.push_back(a[r][c]);
//     for(int i = 0 ; i < 4. ; i++){
//         for(int j = 0 ; j < dr[i] ; j++)
//         {
//             r = r + dy[i];
//             c = c + dx[i];
//             v.push_back(a[r][c]);
//         }
//     }
//     v.pop_back();
    int idx = 0;
    a[str][stc] = v[idx++];
    for(int i = 0 ; i < 4. ; i++){
        for(int j = 0 ; j < dr[i] ; j++)
        {
            str = str + dy[i];
            stc = stc + dx[i];
            if(a[str][stc] != 0) a[str][stc] = v[idx++];
        }
    }

     for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }


}
int main() {
    // Please write your code here.
    
    cin >> n ; 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    r--;
    c--;
    sol(r,c,m1,m2,m3,m4,dir);

    return 0;
}