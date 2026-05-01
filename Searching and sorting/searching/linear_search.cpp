#include<iostream>
using namespace std;
int main (){
    
    // Linear Search 

    int numbers[10]={5,3,8,6,2,7,4,1,9,0};
    int search_value;
    cout<<"Enter the value you want to search\n";
    cin>>search_value;
    int a=0;

    for(int i=0; i<10; i++){
        if(numbers[i] == search_value){
            cout<<"Value found at index "<< i;
            a=1;
            return 0;
        }
    }
    
    if (a==0);
    {
        cout<<"Value not found";
    }

}