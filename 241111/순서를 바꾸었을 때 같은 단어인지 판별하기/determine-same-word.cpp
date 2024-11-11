#include <iostream>
using namespace std;

#include<bits/stdc++.h>

string s1;
string s2;

int main() {
    // 여기에 코드를 작성해주세요.



    cin >>s1;
    cin >>s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i = 0 ; i < min(s1.size(), s2.size()) ; i++)
    {
        if(s2[i] != s2[i]){
            cout <<"No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}