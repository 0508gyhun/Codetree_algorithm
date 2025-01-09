#include <iostream>

using namespace std;
int arrsize;
int tempsize;
int n, m;
int numbers[100];
int temp[101];
bool flag;

void fillzero(int st, int end)
{
    for(int i = st ; i <= end ; i++)
    {
        numbers[i] = 0;
    }
}

int getEndindx(int i, int num)
{
    int idx = i+1;
    for(int j = idx ; j < n ; j ++)
    {
        if(numbers[j] == num) idx++;
        else break;
    }
    return idx-1;
}


void moveToTemp()
{
    tempsize = 0;
    for(int i = 0 ; i < arrsize ; i++)
    {
        if(numbers[i] != 0) temp[tempsize++] = numbers[i];
    }
}
void copy()
{
    arrsize = tempsize;
    for(int i = 0 ; i < arrsize ; i++)
    {
        numbers[i] = temp[i];
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    arrsize = n;
    
    do
    {
        flag = false;
        for(int i = 0 ; i < arrsize ; i++)
        {
            if(numbers[i] == 0) continue;

            int end_idx = getEndindx(i,numbers[i]);
            if(end_idx - i +1 >= m)
            {
                fillzero(i,end_idx);
                flag = true;
            }

        }
        moveToTemp();
        copy();

    }while(flag);
    // Write your code here!

    cout << arrsize << endl;
    for(int i = 0; i < arrsize; i++)
        cout << numbers[i] << endl;

    return 0;


}
