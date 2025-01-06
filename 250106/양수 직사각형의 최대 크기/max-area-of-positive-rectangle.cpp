#include <iostream>

using namespace std;

int n, m;
int a[20][20];



int howmany(int strow, int stcol , int edrow, int edcol)
{
    return (edrow - strow + 1)* (edcol - stcol+1);
}
bool isyang(int strow, int stcol, int edrow, int edcol)
{
    bool res = true;
    for(int  i = strow ; i <= edrow ; i++)
    {
        for(int j = stcol ; j <= edcol ; j++)
        {
            if(a[i][j] < 0 ){
                res = false;
                return res;
            }  
        }
    }
    return res;

}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int mx = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = i; l < n; l++) {
               for (int k = j; k < m; k++) {
                    
                    if(isyang(i,j,l,k))
                    {
                        mx = max(mx, howmany(i,j,l,k));
                    }
                }   
            }
        }
    }
    cout << mx;






    // Write your code here!

    return 0;
}
