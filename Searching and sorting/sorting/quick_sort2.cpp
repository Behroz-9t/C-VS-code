// #include <iostream>
// #include <stdlib.h>
// using namespace std;


// int breaking(int arr[],int low  ,int high)
// {
//     int pivot=arr[low];
//     int p = low + 1; 
//     int q = high;

//     while (true)
//     {
//         while ( p <= high && arr[p] <= pivot)
//         {
//             p++;
//         }
//         while ( arr[q]> pivot)
//         {
//             q--;
//         }
//         if (p>=q)
//         {
//             break;
//         }

//         swap(arr[p],arr[q]);
    
//     }

//     swap(arr[low],arr[q]);


//     return q;
// }



// void quicksort(int arr[],int low , int high)
// {

//     // if (low >= high)
//     // {

//     //     return;
//     // }

//     int q = breaking ( arr, low , high);

//     breaking(arr, low, q-1);
//     breaking(arr, q+1,high);


// }


// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
    
//     int n = 6; // size of the array

//     quicksort(arr, 0, n - 1); // initial array and low and highs are given to the quicksort func

//     //===Simple printing of the array===

//     // ✅ PRINT SORTED ARRAY
//     cout << "Sorted array: ";

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;

// }























#include <iostream>
#include <stdlib.h>
using namespace std;


int breaking(int arr[],int low  ,int high)
{
    int pivot=arr[low];
    int p = low + 1; 
    int q = high;

    while (true)
    {
        while ( p <= high && arr[p] <= pivot)
        {
            p++;
        }
        while ( arr[q]> pivot)
        {
            q--;
        }
        if (p>=q)
        {
            break;
        }

        swap(arr[p],arr[q]);
    
    }

    swap(arr[low],arr[q]);


    return q;
}



void quicksort(int arr[],int low , int high)
{

    if (low >= high)
    {

         return;
	}

    int q = breaking(arr, low , high);

    quicksort(arr, low, q-1);
    quicksort(arr, q+1,high);


}


int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    
    int n = 6; // size of the array

    quicksort(arr, 0, n - 1); // initial array and low and highs are given to the quicksort func

    //===Simple printing of the array===

    // ? PRINT SORTED ARRAY
    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;

}