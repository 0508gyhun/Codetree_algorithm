#include <iostream>
using namespace std;


int numofmonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {


    int m1,m2,d1,d2;
    cin >> m1 >> d1 >> m2 >> d2;

    int day= d2;
    int totalday = 0 ;
    while(1)
    {
        if(m1 == m2 && day == d2) break;
        day++;
        totalday++;

        if(numofmonth[m1]< day)
        {
            m1++;
            day = 1;
        }
    }
    cout <<totalday+1 ; 


    // 여기에 코드를 작성해주세요.
    return 0;
}