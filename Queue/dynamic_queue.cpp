#include<iostream>
#include<stdlib.h>
using namespace std;

struct dqueue
{
    int data;
    dqueue*next;
}; 

dqueue*front=NULL;
dqueue*rear= NULL;


void Enqueue(int value)
{
    dqueue*temp;
    temp=(dqueue*)malloc(sizeof(dqueue));
    temp->data=value;
    temp->next=nullptr;

    if (front ==NULL & rear == NULL) // if both front and rear is null the assign the temp to front and rear which is the first cond if queueing the first elemnt
    {
        front=temp;
        rear=temp;
        temp->next=front;

        cout<<"\nThe value successfully queued\n";
        
    }
    
    else
    {
        rear->next=temp; // used the rear because it is always pointing to the end
        rear=temp;  // then we point the rear to the new last elemnt

        temp->next=front;
        
        cout<<"\nThe value successfully queued\n";


    }


}





void Dequeue()
{
    dqueue*curr=front;
   
    
    if(front==NULL) // cond 1 queue is empty
    {
        cout<<"List is empty, deletion not possible"<<endl;
        return;
    }

    if (front==rear) // cond 2 only one element present
    {
        free (curr);
        cout<<"\nValue Dequeued\n";
        rear=NULL;
        front=NULL;
        return;
    }


    else // cond 3 more than one element
    {
        rear->next=front->next;
        front=front->next;

        free(curr);
        cout<<"\nValue Dequeued\n";
        return;
    }
    

}







void display()
{
    if(  front == NULL && rear == NULL)
    {
        cout<<"Queue is in underflow condition"<<endl;
        return;
    }

    dqueue*curr=front;
    cout<<"\nThe front: "<<front->data<<" and the rear: "<<rear->data<<endl;
    do
    {
        cout<<curr->data<<endl;
        curr=curr->next;
    
    } while (curr!=front);
    
    
    // {

    //     cout<<curr->data<<" ";
    //     curr=curr->next;

    //     while(curr!=front)
    //     {
            
    //         cout<<curr->data<<" ";
    //         curr=curr->next;
    //     }
    //     cout<<endl;
    // }
}


int main()
{
    int choice, val,num; 
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Enqueue \n2. Dequeue\n3. Display Queue\n";
        cout << "Enter choice: ";
        cin >> choice; 
        
        switch(choice) 
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                Enqueue(val);
                break;
            
            case 2:
                Dequeue();
                break;

            case 3:
                display();
                break;

    

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;

}


