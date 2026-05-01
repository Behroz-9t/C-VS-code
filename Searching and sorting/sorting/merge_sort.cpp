#include <iostream>
#include<stdlib.h>
using namespace std;


int merge(int arr[],int left, int right, int mid)
{
    int i = left;
    int j = mid +1;
    int k=left;
    int temp[100];

    while (  i <= mid & j<= right)
    {
        if (arr[i]<arr[j])
        {
            temp [k]=arr[i];
            i++;


        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;

    }



    for(int x=left;x<=right;x++)
    {
        arr[x]=temp[x];
    }
    return 0;
}



void divide(int arr[],int left,int right)
{
    // right=9;
    if (left<right)
    { 
        int mid=(left+right)/2;
        divide(arr,left,mid);
        divide(arr,mid+1,right);
        merge(arr,left,right,mid);
        return;
    }
}

int main ()
{
    int arr[10]={2,4,1,7,93,89,73,22,44,21};
    int n=10;
    int right=9;

    divide(arr,0,right);

    for (int i=1;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }


    



}

