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
    
    int ind = value % 13;// index  3

    int check = ind; //
    
    while (arr[ind]!= -1)
    {   
        ind=(ind+1) % 13; // linear probing

        if (ind==check)
        {
            cout<<"The array is Full";
            return;
        }
        
    }
    
    arr[ind]=value; 
    
    
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