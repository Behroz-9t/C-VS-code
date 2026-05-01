#include<iostream>
using namespace std;
int main (){
    
    // Binary Search 
     
    int numbers[10]={1,3,5,13,45,90,155,156,200,210};
    int search_value;
    cout<<"Enter the value you want to search\n";
    cin>>search_value;
    int l=0,r=9,mid;

    while(l<=r)
    {
        mid=(l+r)/2;
        if(search_value == numbers[mid])
        {
            cout<<"Value found ";
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