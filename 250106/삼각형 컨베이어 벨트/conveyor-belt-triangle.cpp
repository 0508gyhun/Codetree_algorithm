#include <iostream>
using namespace std;

int n,t;
int a[204];


int main() {
    // Please write your code here.
    cin>> n >> t;


   
   for(int i = 0 ; i < n ; i++) cin >> a[i];
   for(int i = n ; i < 2*n ; i++) cin >> a[i];
   for(int i = 2*n ; i < 3*n ; i++) cin >> a[i];


for(int k = 0 ; k < t ; k++)
{
    int temp = a[3*n-1];
    for(int i = 3*n-1 ; i >0 ; i++){
        a[i] = a[i-1];
   }
   a[0] = temp;

}

  for(int i = 0 ; i < n ; i++) cout<< a[i]<<" "<< endl;
   for(int i = n ; i < 2*n ; i++) cout<< a[i]<<" "<< endl;
   for(int i = 2*n ; i < 3*n ; i++) cout << a[i]<<" ";




    return 0;
}