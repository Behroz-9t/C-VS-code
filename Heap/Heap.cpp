#include<iostream>
#include<stdio.h>

using namespace std;


int arr[7];

// The size of empty array
int sizeofarray=7;


int indexes()
{
    for (size_t i = 0; i < sizeofarray; i++)
    {
        arr[i] = -1;
    }
    return 0;
    
}

void upheapify(int arr[],int i)
{
    
    if(i == 0)
    {return;}   // base condition for the recurrsion termination

    int parent = (i - 1)/2;  // every new parent calculation 

    if (arr[parent]<arr[i])  // Check if the parent is always the greatest
    {

        // swaping mechanism
        int temp;
        temp=arr[i];
        arr[i]=arr[parent];
        arr[parent]=temp;

    }
    upheapify(arr,parent);   // upheapify recursive call with paret as an i 
    
}

// variable size of the array
int heapsize = 0;  

int insert(int val)
{
    
    int parent;

        if (heapsize==0) // if the array is empty
        {
            arr[heapsize]=val;  // no need to call upheapify
            heapsize++;         // increased the size of array
            return 0;
        }
        else
        {
            if (heapsize < sizeofarray)
            {
                arr[heapsize]=val;  // inserts the value in the array
                
                upheapify(arr,heapsize);  // then checks for the abnormality
                heapsize++;
            }
            else
            {
                cout<<"Heap is FULL"<<endl;
                // heapsize--;
                return 0;
            }

        }

    return 0;
    

// int index = size;
// size++;
// arr[index] = value;
// unheapify();


}

void downheapify(int arr[],int i,int size)
{
    int parent, leftChild, RightChild, temp;

    parent=(i - 1)/2;

    leftChild =  (2* parent) + 1;
    RightChild = (2* parent) + 2;

    if ( leftChild < size )
    {
        if ( RightChild < size)
        {
            if ( arr[RightChild] > arr[leftChild] )
            {
                temp=arr[RightChild];
                arr[RightChild]=arr[parent];
                arr[parent]=temp;
                downheapify(arr,RightChild+4,size);
                
            }
            else
            {
                temp=arr[leftChild];
                arr[leftChild]=arr[parent];
                arr[parent]=temp;
                downheapify(arr,leftChild+2,size);
           }

        }
        else
        {
            temp=arr[leftChild];
            arr[leftChild]=arr[parent];
            arr[parent]=temp;

        }
    }
    else
    {
        return;
    }




}


int Delete()
{
    
    int index=0;

    //swaping first
    arr[0]=arr[heapsize-1];
    

    // delete last value manually
    heapsize--;
    sizeofarray--;

    //down heapify
    downheapify(arr,index,heapsize);
    return 0;


}


void display ()
{
    for (size_t i = 0; i < sizeofarray; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}



void FullHeapDisplay()
{
    int level = 0;
    int count = 0;

    for (int i = 0; i < heapsize; i++)
    {
        cout << arr[i] << " ";
        count++;

        if (count == (1 << level)) 
        {
            cout << endl;
            level++;
            count = 0;
        }
    }
    
}



int main()
{
    
    int choice, val,num,output; 
   
    
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert \n2. Display\n3. Delete\n4. FullHeapDisplay\n";
        cout << "\nEnter choice: ";
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
                
            case 3:
                Delete(); 
                break;

            case 4:
                FullHeapDisplay(); 
                break;

        }
    }
    return 0;

}
