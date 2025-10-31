#include <iostream>
#include <bits/stdc++.h>


using namespace std;

vector<int> v;

int n;
int numbers[3] = {4,5,6};



bool isEqual(int st1, int end1, int st2, int end2) {
    for(int i = 0 ; i <= end1 - st1 ; i++) {
        if(v[i+st1] != v[st2+i]) return false;
    }
    return true;
}

bool possible() {
    int len = 1;

    while(true) {
        int end1 = (int)v.size()-1;
        int st1 = end1-len+1;

        int end2 = st1 - 1;
        int st2 = end2-len+1;

        if(st2 < 0) break;

        if(isEqual(st1,end1,st2,end2)) {
            return false;
        }
        len++;
    }
    return true;
}


void go(int idx) {
    if(idx  == n) {
        for(int i : v) {
            cout <<i ;
        }
        exit(0);
    }


    for(int i = 0 ; i < 3 ; i++) {
        v.push_back(numbers[i]);
        if(possible()) {
            go(idx+1);
        }
        v.pop_back();
    }
}

int main() {
    cin >> n;
   
    // Please write your code here.

    go(0);
    return 0;
}
