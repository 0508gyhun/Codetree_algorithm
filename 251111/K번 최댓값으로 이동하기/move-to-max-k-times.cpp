#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int grid[100][100];
int r, c;
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
 // 1 00 00 00
    cin >> r >> c;
    r--;
    c--;
    int mr = r;
    int mc = c;
    int st = grid[r][c] ;
    while(k--) {
        int mx = INT_MIN;
        bool flagg = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(st > grid[i][j])
                {
                    mx = max(mx, grid[i][j]);
                   flagg = 1;
                }
            }
        }
        if(flagg == 0 )
        {

        }
        else
        {
            bool flag = 0 ;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(mx == grid[i][j])
                    {
                        mr = i;
                        mc = j;
                        flag = 1;
                        break;
                   
                    }
                }
                if(flag) break;
            }
        }
        // cout << "mx = "<< mx <<endl;
        
        // cout << mr <<" "<< mc << endl;
        st = grid[mr][mc];
    }

    cout << mr<<" "<<mc << endl;
    // Please write your code here.

    return 0;
}
