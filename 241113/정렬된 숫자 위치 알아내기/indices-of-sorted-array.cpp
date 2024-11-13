#include <iostream>
#include <algorithm>
#include <iomanip> 


using namespace std;


class person{
    public:
        int x;
        int idx_num;

    person(int x, int idx_num)
    {
        this->x = x;
        
        this->idx_num = idx_num;
    }
    person(){

    }

        
};


bool cmp1(person a , person b)
{
    if( a.x != b.x ) return a.x < b.x;
    return a.idx_num < b.idx_num;
}

int n ; 
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n ;

    person parr[n];
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        parr[i] = person(x,i+1);
    }
   
    sort(parr, parr+ n , cmp1);
    

    int result[n] ; 

    
    for(int i = 0 ; i < n ; i++)
    {
        result[parr[i].idx_num] = i+1;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        cout << result[i]<<" ";
    }
   
   
    return 0;
}