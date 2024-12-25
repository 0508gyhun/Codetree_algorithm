#include <iostream>
using namespace std;
int n;
int arr[100004];



int partition(int arr[], int low, int high)
{
    int i = low-1;
    int pivot = arr[high];
    for(int j = low ; j < high ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}


void quicksort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pos = partition(arr,low,high);

        quicksort(arr,low,pos-1);
        quicksort(arr,pos+1,high);
    }
}


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int i = 0 ;i < n ; i++)
    {
        cin >> arr[i];
    }


    quicksort(arr,0,n-1);
    for(int i = 0 ; i < n ; i++)cout << arr[i]<<" ";
    return 0;
}