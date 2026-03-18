#include <iostream>

using namespace std;

int n, m;
int A[100004];
int B[100004];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    int i = 0; // A

    for(int j = 1 ; j <= m ; j++)
    {
        while(i+1 <= n && A[i+1] != B[j])
        {
            i++;
        }


        if(i == n+1)
        {
            cout << "No" << endl;
            return 0;
        }

        i++;
    }

    cout<< "Yes" << endl;

    // Please write your code here.

    return 0;
}
