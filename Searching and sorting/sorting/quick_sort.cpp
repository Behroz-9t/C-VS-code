#include <iostream>
using namespace std;


// Covered in mid paper

void quickSort (int arr[], int left, int right)
{
   if (left >= right) return;
   //left = 0 , right = 9
   int pivot = arr[(left + right)/2];
   int i = left, j = right;

   while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}




int main () 
{
   
    int arr[] = {77,82,11,54,76,57,25,98,59,101};
    int n = 10;
    int right = n - 1;
    int left = 0;
    quickSort(arr, left, right);

     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
     }
     return 0;
}