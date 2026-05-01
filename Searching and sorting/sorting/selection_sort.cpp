#include<iostream>
using namespace std;
int main ()
{
    // selection sort

    int numbers[6]={3,4,1,7,6,9};
    int num_length=6;

    for (int i=0;i<num_length-1;i++)
    {
        int min = i;
        for (int j=i+1;j<num_length;j++)
        {
            if (numbers[j]<numbers[min])
            {
                min=j;
            }
        }

        if (min!= i)
        {
            swap(numbers[i],numbers[min]);
        }
    }

    
    for (int k = 0; k < num_length; k++)
    {
       
        cout << numbers[k];
        cout<<" ";
    }
    
    return 0;
}
