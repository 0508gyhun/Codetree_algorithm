#include <iostream>
using namespace std;

                      //1 2 3.  4  5. 6  7. 8  9. 10 11 12
int day_month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

string week[15] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat","Sun","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
int howmanydays(int m, int d)
{
    int total = 0 ;

    for(int i = 1 ; i <= m ; i++)
    {
        total += day_month[i];
    }
    return total+d;
}


int main() {
    // 여기에 코드를 작성해주세요.

    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2>> d2;
    
    int res = (howmanydays(m2,d2) - howmanydays(m1,d1));
   // cout << res<< endl;
    res = res%7;
   // cout << res<< endl;


    int currentidx = 8;
    int ansidx = currentidx+res-1;
    

    cout << week[ansidx];
    


    return 0;
}