#include <iostream>
#include <algorithm>
#include <iomanip> 


using namespace std;


class person{
    public:
        int idx;
        int ki;
        int mom;

    person(int ki , int mom,int idx )
    {
        this->idx = idx;
        this->ki = ki;
        this->mom = mom;
    }
    person(){

    }

        
};


bool cmp1(person a , person b)
{
    if(a.ki != b.ki) return a.ki < b.ki;
    else return a.mom> b.mom;
}
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    
    
    cin >> n ;


    person parr[n];
    for(int i = 0 ; i < n ; i++)
    {
        int ki,mom;
        cin >> ki>>mom;
        parr[i] = person(ki,mom,i+1);

    }
    
    sort(parr, parr+ n , cmp1);
    //cout << "name "<< endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << parr[i].ki<<" "<<parr[i].mom<<" "<<parr[i].idx<< endl;
    }
    
    return 0;
}