#include <iostream>
using namespace std;
int n =3;
int a[3][3];

int main() {
    // 여기에 코드를 작성해주세요.

    for(int i = 0 ; i < n ; i++)
    {
        string s;
        cin >>s;
        for(int j = 0 ; j < n ; j++)
        {
            a[i][j] = s[j]-'0';
        }
    }
    int cnt = 0;

    for(int i = 1 ; i < 10 ; i++)
    {
        for(int j = i+1 ; j < 10 ; j++)
        {
            //가로
            for(int p = 0 ; p < 3 ; p++)
            {
                if( (a[p][0] == i || a[p][0] == j)&& (a[p][1] == i || a[p][1] == j) && (a[p][2] == i || a[p][2] == j)) cnt++;

            }
            //세로
            for(int p = 0 ; p < 3 ; p++)
            {
                if( (a[0][p] == i || a[0][p] == j)&& (a[1][p] == i || a[1][p] == j) && (a[2][p] == i || a[2][p] == j)) cnt++;

            }
            if( (a[0][0] == i || a[0][0] == j)&& (a[1][1] == i || a[1][1] == j) && (a[2][2] == i || a[2][2] == j)) cnt++;
            if( (a[0][2] == i || a[0][2] == j)&& (a[1][1] == i || a[1][1] == j) && (a[2][0] == i || a[2][0] == j)) cnt++;
            
            //세로

            //대각
        }
    }

    cout << cnt;
    return 0;
}