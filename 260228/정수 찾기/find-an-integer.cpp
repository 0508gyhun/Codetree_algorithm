#include <iostream>

using namespace std;

int n;
int m;
int arr1[100000];
int arr2[100000];

int main() {
    // cin >> n;
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        s.insert(arr1[i]);
    }

    // cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        if(s.find(arr2[i]) != s.end())
        {
            cout << "1"<<" ";
        }
        else
        {
            cout << "0"<<" ";
        }
    }


    // Please write your code here.

    return 0;
}
