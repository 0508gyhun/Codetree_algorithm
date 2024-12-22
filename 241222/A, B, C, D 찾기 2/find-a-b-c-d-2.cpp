#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,ab,bc,cd,da,ac,bd,abc,abd,acd,bcd,abcd;
int arr[15];

int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> v1;

    for(int i = 0 ; i < 15 ; i++)
    {
        cin >> arr[i]; 
        v1.push_back(arr[i]);
    }
    sort(v1.begin(),v1.end());

    for(int i = 1 ; i <= 40 ; i++)
    {
        for(int j = 1 ; j <= 40 ; j++)
        {
            for(int p = 1 ; p <= 40 ; p++)
            {
                for(int q = 1 ; q<=40 ; q++)
                {
                    vector<int> v2;
                    a = i;
                    b = j;
                    c = p;
                    d = q;
                    ab = i+j;
                    bc = j+p;
                    cd = p+q;
                    da = i+q;
                    ac = i+p;
                    bd = j+q;
                    abc = i+j+p;
                    abd = i+j+q;
                    acd = i+p+q;
                    bcd = j+p+q;
                    abcd = i+j+p+q;
                    v2.push_back(a);
                    v2.push_back(b);
                    v2.push_back(c);
                    v2.push_back(d);
                    v2.push_back(ab);
                    
                    v2.push_back(bc);
                    v2.push_back(cd);
                    v2.push_back(da);
                    v2.push_back(ac);
                    v2.push_back(bd);

                    v2.push_back(abc);
                    v2.push_back(abd);
                    v2.push_back(acd);
                    v2.push_back(bcd);
                    v2.push_back(abcd);
                    sort(v2.begin(), v2.end());
                    if(v1==v2)
                    {
                        cout << a<<" "<<b<<" "<<c<<" "<<d;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}