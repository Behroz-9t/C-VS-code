#include<iostream>
using namespace std;
int main (){

    // Binary Search with Duplicates

    int numbers[10]={1,3,13,13,13,13,155,156,200};
    int search_value;
    cout<<"Enter the value you want to search\n";
    cin>>search_value;
    int l=0,r=9,mid;

    while(l<=r)
    {
        mid=(l+r)/2;
        if(search_value == numbers[mid])
        {
            int count=1;
        
            l = mid - 1;
            while ( numbers[l] == search_value) {
                count++;
                l--;
            }

            r = mid + 1;
            while ( numbers[r] == search_value) {
                count++;
                r++;
            }
            cout<<"Value found "<< count <<" times";
            break;
                    
        }
            
        else if (search_value>numbers[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    
    if (l>r)
    {
        cout<<"Value not found";
    }

}