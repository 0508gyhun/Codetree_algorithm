#include <iostream>
using namespace std;


int n,k;
int a[11][21];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> k >> n;

    for(int i = 0 ; i < k ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0; 

    for(int i=1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == j)continue;
            bool correct = true;

            for(int p = 0 ; p< k ; p++)
            {
                int idxi = 0, idxj =0;
                for(int q = 0 ; q<n ; q++)
                {
                    if(a[p][q] == i)
                    {
                        idxi = q;
                    }
                    if(a[p][q] == j)
                    {
                        idxj = q;
                    }
                }
                if(idxi > idxj) correct = false;

            }
            if(correct) ans++;
        }

    }
    cout << ans;

    return 0;
}