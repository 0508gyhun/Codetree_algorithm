#include <iostream>

using namespace std;

int N;
int mem[46];
int fibo(int n) 
{
    if(mem[n] != -1) 
    {
        return mem[n];
    }

    if(n >= 3)
    {
        mem[n] = fibo(n-1) + fibo(n-2);
    }

    return mem[n];
}


int main() {
    cin >> N;
    fill(mem, mem+46, -1);
    mem[1] = 1;
    mem[2] = 1;
    cout << fibo(N);
    // Please write your code here.

    return 0;
}
