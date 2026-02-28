#include <iostream>
#include <set>
using namespace std;

const int MAX_N = 100000;
int n;
int arr[MAX_N];
set <int> s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    cout <<s.size();

    // Please write your code here.

    return 0;
}
