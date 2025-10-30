#include <iostream>
#include <bits/stdc++.h>


using namespace std;

string s;
set<char> st;

vector<char> opr;
vector<int> v;
vector<char> stv;

int num;
map<char,int> mp;
int mx = INT_MIN;

//1~4 중 1개를 N 번
void prt() {
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void setToMap() {
    mp.clear();

    for(int i = 0 ; i < stv.size() ; i++) {
        int num = v[i];
        char c = stv[i];
        mp[c] = num;
    }
    int num = 0;
    char op = '+';
    int ans = 0 ;
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            char str = s[i];
             num = mp[str]; 
             if(op == '+') ans = ans+num;
             else if(op == '-') ans = ans - num;
             else if (op == '*')ans  = ans*num;
        }
        else {
            if(s[i] == '+') op = '+';
            else if(s[i] == '-') op = '-';
            else if(s[i] == '*') op = '*';
        }
        
    }
    mx = max(mx, ans);
}

void go(int idx) {
    if(idx == num) {
        setToMap();
        // prt();
        return;
    }

    for(int i = 1 ; i <5 ; i++) {
        v.push_back(i);
        go(idx+1);
        v.pop_back();
    }

    
}
int main() {
    cin >> s;


    // Please write your code here.

    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') st.insert(s[i]);
        else opr.push_back(s[i]);
    }
    for(int i : st) {
        stv.push_back(i);
    }
    num = st.size();
    // cout << num<< endl;
    go(0);
    cout << mx;
    return 0;
}
