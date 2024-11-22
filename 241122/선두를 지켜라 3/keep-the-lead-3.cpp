#include <iostream>
using namespace std;

int a[1000004];
int b[1000004];
int n,m;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>> m;

    int cur = 1;
    for(int i = 0 ; i < n ; i++)
    {
        int v,t;
        cin >> v>>t;
        while(t--)
        {
            a[cur] = a[cur-1]+v;
            cur++;
        }
    }

    for(int i = 0 ; i < cur ; i++)
    {
        cout << a[i] << " ";
    }

    cur = 1;
    for(int i = 0 ; i < n ; i++)
    {
        int v,t;
        cin >> v>>t;
        while(t--)
        {
            b[cur] = b[cur-1]+v;
            cur++;
        }
    }
    cout << endl;
    for(int i = 0 ; i < cur ; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}