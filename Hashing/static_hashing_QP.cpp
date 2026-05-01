#include<iostream>
#include<stdlib.h>
using namespace std;


int arr [13];

void init() 
{
    for (int i = 0; i < 13; i++) 
    {
        arr[i] = -1;  // -1 means the slot is empty
    }
}



void insert (int value)
{

    // ======== Mid paper ==========
    // hash function: H(f) = (3(f)+4) % 10
    // Quadratic probing 

    int hash = value % 13;  // H(f) = (3(f)+4) % 10 --> here f is the values of the array
    
    int var=0;
    int ind;
    
    while (var<13)
    {   
       
            ind=(hash+(var*var)) % 13; // quadratic probing

            if (arr[ind]==-1)
            {
                arr[ind] = value;
                return;
            }
            var++;
          
            
    }
        
    cout<<"The array is Full";
       
    
    
    
}


void display()
{
    for (int i=0;i<13;i++)
    {
        
        
        cout<<arr[i]<<endl;
    }
}



void display2()
{
    cout << "\nHash Table:\n";
    for (int i = 0; i < 13; i++)
    {
        cout << i << " : ";
        if (arr[i] == -1)
        cout << "EMPTY";
        else
        cout << arr[i];
        cout << endl;
    }
}








int main()
{
    int choice, val,num; 
    init ();
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert  \n2. Display  \n";
        cout << "Enter choice: ";
        cin >> choice; 
        
        switch(choice) 
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                insert(val);
                break;

            case 2:
                
                display();
                break;
        }
    }
}