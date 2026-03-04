#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;

int N;
string command;
priority_queue <int> pq;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            pq.push(x);
        }
        if(command == "pop")
        {
            cout<< pq.top()<<endl;
            pq.pop();
        }
        if(command == "size")
        {
            cout <<pq.size()<<endl;
        }
        if(command == "empty")
        {
            cout << pq.empty() <<endl;
        }
        if(command == "top")
        {
            cout <<pq.top()<<endl;
        }

    }

    // Please write your code here.

    return 0;
}
