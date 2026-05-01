#include<iostream>
using namespace std;
int main ()
{
    // bubble sort

    int numbers[6]={3,4,1,7,6,9};
    int num_length=6;
    int temp;

    for (int i=0;i<num_length-1;i++)
    {
        for (int j=0;j<num_length-1-i;j++)
        {
            if (numbers[j]>numbers[j+1])
            {
                temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;

            }
        }

    }

    for ( int k =0; k<num_length;k++){
        cout<<numbers[k];
        cout<<" ";
    }



}
