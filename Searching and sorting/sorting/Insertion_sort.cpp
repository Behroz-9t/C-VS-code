#include<iostream>
using namespace std;
int main ()
{
    int numbers[6]={3,4,1,7,6,9};
    int num_length=6;

    for (int i=1;i<num_length;i++)
    {
        int hold =numbers[i];
        int gap =i;

        while (gap>0 )
        {
            if (hold<numbers[gap-1])
            {
                numbers[gap]=numbers[gap-1];
                gap--;
            }
            else{
                break;
            }
        }
        numbers[gap]=hold;
        
    }


    for ( int k =0; k<num_length;k++){
        cout<<numbers[k];
        cout<<" ";
    }
}