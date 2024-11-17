#include <iostream>
using namespace std;

int n ; 
int b,w;

int num;
char dir;
int a[200004];

int cur = 100000;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n ;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> num >> dir;

        if(dir == 'R')
        {
            for(int j = 0 ; j < num ; j ++)
            {
                a[cur] = 1;
                if(j != num-1)cur++;
            }
        }
        else if(dir == 'L')
        {
            for(int j = 0 ; j < num ; j++)
            {
                a[cur]=2;
                if(j!=num-1)cur--;
            }
        }
    }

    for(int i = 0 ; i < 200004; i++)
    {
        if(a[i] == 1) b++;
        else if (a[i] == 2) w++;
    }

    cout << w << " "<< b;
    return 0;
}