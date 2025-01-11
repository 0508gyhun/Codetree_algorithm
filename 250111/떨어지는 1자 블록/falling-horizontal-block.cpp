#include <iostream>

using namespace std;

int n, m, k;
int arr[100][100];
bool isyeonsok(int row)
{
    bool ans = true;
    for(int i = k ; i < k+m ; i++)
    {
        if(arr[row][i] !=0) ans = false;
    }
    return ans;
}

void paint(int row, int stcol, int endcol)
{
    for(int i = stcol; i < endcol ; i++)
    {
        arr[row][i] = 1;
    }
}


int main() {
    cin >> n >> m >> k;
 //1*m  크기의 k열 부터 ㄷ시작.
    k--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

   
    for(int i = 0 ; i < n ; i++)
    {
        int row, stcol, endcol;
        bool flag = true;
        if(isyeonsok(i))
        {
            row = i;
            stcol = k;
            endcol = k+m;

            // cout <<"is 연속"<< endl;
            // cout << row<<" "<<stcol <<" "<< endcol << endl;
        }
        else{
            //  cout <<"not 연속"<< endl;
            // cout << row<<" "<<stcol <<" "<< endcol << endl;
            paint(row, stcol, endcol);
            break;
           

        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Write your code here!

    return 0;
}
