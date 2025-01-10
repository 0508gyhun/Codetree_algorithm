#include <iostream>

using namespace std;

int n,m,k;
int arr[100][100];
int temp[101][101];

int findendidx(int col, int st, int num)
{
    int idx = st-1;
    for(int i = idx ; i>= 0 ; i --)
    {
        if(arr[i][col] == num) idx--;
        else break;
    }
    return idx+1;
}
void bomb()
{
    //연속 m개 이상 이면 0,

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = n-1 ; j >=0 ; j--)
        {
            if(arr[j][i] == 0) continue;
            int endidx = findendidx(i, j , arr[j][i]);
            if(abs(endidx - j) +1 >= m)
            {
                for(int k = endidx ;k <= j ; k++)
                {
                    arr[k][i] = 0;
                }
            }
           
        }
    }


}
void print()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

void down ()
{
    for(int i= 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            temp[i][j] = 0;
        }
    }

    for(int i= 0 ; i < n ; i++)
    {
        int idx = n-1;
        for(int j = n-1 ; j >= 0; j--)
        {
            if(arr[j][i] != 0 ) temp[idx--][i] = arr[j][i];
        }
    }
    for(int i= 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
           arr[i][j] = temp[i][j];
        }   
    }
           


}

void rotateRight()
{
    for(int i= 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            temp[i][j] = 0;
        }
    }
    for(int i= 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            temp[j][n-1-i] = arr[i][j];
        }   
    }
    for(int i= 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
}

bool ispossible()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = n-1 ; j >=0 ; j--)
        {
            if(arr[j][i] == 0) continue;
            int endidx = findendidx(i, j , arr[j][i]);
            if(abs(endidx - j) +1 >= m)
            {
                return true;
            }
           
        }
    } 
    return false;  
}

int count()
{
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(arr[i][j] > 0) cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> n>>m>>k;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    // bomb();
    // cout << "after bomb"<<endl;
    // print();
    // down();
    // cout << "after down"<<endl;

    // print();
    // rotateRight();
    // cout << "after rotate"<<endl;

    // print();
    // down();
    // cout << "after down"<<endl;
    
    // print();

    while(k--)
    {
        bomb();
        down();
        rotateRight();
        down();
    }
    while(ispossible())
    {
        bomb();
        down();
        rotateRight();
        down();
    }
    
    

    cout << count() <<endl;
    
   

    return 0;
}
