#include <iostream>

using namespace std;

int arr[4][4];
int temp[4][4];
int templus[4][4];
char dir;

void rotaterighgt()
{
    for(int i = 3 ; i >= 0 ; i--)
    {
        for(int j = 3 ; j >= 0 ; j--)
        {
            temp[j][4-1-i] = arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = temp[i][j];
        }
    }

}
void plus_()
{
    //temp 에 있는 것을 temp_plus로 더해서 표현
    for(int i = 0 ; i < 4 ; i++)
    {
        int prev = arr[3][i];
        for(int j = 3 ; j > 0 ; j--)
        {
            if( arr[j][i] == arr[j-1][i] )
            {
                int sum = arr[j][i]+ arr[j-1][i];
                arr[j][i] = sum;
                arr[j-1][i] = 0;
            }
        }
    }
    // cout<<" after plus"<<endl;

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout<< arr[i][j] <<" ";
    //     }
    //     cout << endl;
    // }

}

void down()
{//arr->templus
    for (int i = 0; i < 4; i++) {
      int idx= 3;
        for (int j = 3 ; j >= 0; j--) {
            if(arr[j][i] != 0)  templus[idx--][i] = arr[j][i]; 
        }
       // cout << endl;
    }

     for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = templus[i][j];
        }
    }

    // cout << "after down" << endl;
    //  for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout<< arr[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
}
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> dir;

    // cout << endl;

    // Write your code here!
    if(dir == 'L')
    {
        //오른쪽으로 90 회전 row = n-1 , col = n-1 // r & c reverse

       rotaterighgt();
       rotaterighgt();
       rotaterighgt();
        
    }
    else if(dir == 'R')
    {
        // 왼쪽으로 90
        rotaterighgt(); // 이따 오른으로 3번ㄴ 더 
      

    }
    else if (dir == 'U')
    {
        
        rotaterighgt();
        rotaterighgt();

    }
    else if (dir == 'D')
    {
    }


    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout<< arr[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    plus_();
    down();


    // Write your code here!
    if(dir == 'L')
    {
        //오른쪽으로 90 회전 row = n-1 , col = n-1 // r & c reverse

       rotaterighgt();
        
    }
    else if(dir == 'R')
    {
        // 왼쪽으로 90
        rotaterighgt(); 
        rotaterighgt();
        rotaterighgt();
      

    }
    else if (dir == 'U')
    {
     
        rotaterighgt();
        rotaterighgt();
   
    }
    else if (dir == 'D')
    {
        
    }
    // cout <<"final"<< endl;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout<< arr[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}
