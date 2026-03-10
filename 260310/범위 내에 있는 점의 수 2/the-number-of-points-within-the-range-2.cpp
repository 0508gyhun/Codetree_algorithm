#include <iostream>

using namespace std;
#define max_n 100004
#define max_a 1000004
int N, Q;
int points[100000];
int A[100000], B[100000];
int psum[max_a+4];

int getSum(int s, int e)
{
    if(s == 0) return psum[e];
    else
    {
        return psum[e] - psum[s-1];
    }
}

int main() {
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> points[i];
        psum[points[i]]++;
    }

    for(int i = 1 ; i <= max_a ; i++)
    {
        psum[i] += psum[i-1];
    }

    for (int i = 1; i <= Q; i++) {
        cin >> A[i] >> B[i];
        cout <<getSum(A[i], B[i]) << endl;
    }

    // Please write your code here.

    return 0;
}
