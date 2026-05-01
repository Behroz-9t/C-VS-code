#include<iostream>
using namespace std;
int main (){
    

    // Linear Search with Duplicates

    int numbers[10]={5,3,8,6,2, 3,4,1,9,3};
    int search_value;
    cout<<"Enter the value you want to search\n";
    cin>>search_value;
    int a=0;

    for(int i=0; i<10; i++){
        if(numbers[i] == search_value){
            cout<<"\nValue found at index "<< i;
            a=1;
            
        }
    }
    
    if (a==0)
    {
        cout<<"Value not found";
    }

}