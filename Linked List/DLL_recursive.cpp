#include<iostream>
#include<stdlib.h>
using namespace std;

struct DLLNode
{
    int data;
    DLLNode*next=NULL;  //Pointer to next node
    DLLNode*prev=NULL; // pointer to the prev node

};

DLLNode*list=NULL;   // Global pointer to the head of the list 
                     // (It sits outside the function (global scope) and holds the address of the very first node).

void insert(int value)
{
    DLLNode*temp;
    
    
    temp=(DLLNode*)malloc(sizeof(DLLNode));
    temp->data=value;

    
    if (list==NULL) // if the list is NULL 
    {
        list=temp;  // list is given the address 
        list->prev=NULL;  // because it is the only elemnt in the list so the prev is NULL bcaus it is a double list
        temp->next=NULL; // and the next of the temp is also NULL
    }
    else  // else if there is already elemnt present
    {
        DLLNode*curr=list; //curr points to list
        while(curr->next!=NULL) // iterates the curr till the last elemt so that the elemnt is inserted at the last
        {

            curr=curr->next;
        }
        curr->next=temp; // here the curr is last elemnt so that the curr next has the temp now
        temp->next=NULL; // temp next is NULL 
        temp->prev=curr; // temp prev is curr bcause it is a two way connection now
    }
}

void display()
{
    // 1. Handle empty list case first
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    DLLNode* curr = list;
    
    // 2. Forward Traversal
    cout << "Forward: ";
    while (curr!= NULL) // Only here and in the single linked list, we can put this condition of the curr is not NULL because here the first elemnt prev and last elemnt's next is NULL and there the last's next is null.
    {
        cout << curr->data << " ";

        if (curr->next == NULL) // every time the loop executes, it fully iterates to the end of the list where the curr's next becomes NULL whixh becomes the problem when iterating backwards
        {
            break; // Stop the loop while 'curr' is pointing to the tail
        }
        curr = curr->next; // calls curr next for the printing purpose
    }
    cout << endl;
    
    // At this point, 'curr' is pointing to the last node (Tail)

    char ans;
    cout<<"Do you want to get a peak at the reverse order display? y/n: ";
    cin>>ans;

    if (ans == 'y')
    {

        
        // 3. Backward Traversal
        cout << "Backward: ";
        while (curr != NULL)
        {
            cout << curr->data << " "; // accessing the data to move backwards through the prev
            if (curr->prev == NULL) // every time the loop executes, it fully iterates to the end of the list where the curr's next becomes NULL whixh becomes the problem when iterating backwards
        {
            break; // Stop the loop while 'curr' is pointing to the head
        }
            curr = curr->prev; // Move backwards
        }
        cout << endl;
    }
    else{
        cout<<"Okay, FINE!"<<endl;
    }
}












void RecursiveDisplayF(DLLNode* i)
{
    DLLNode*curr=i;
    
    if (curr==NULL)
    {
        return;
    }

    cout<<curr->data<<endl;
    
    RecursiveDisplayF(curr->next);
    // curr=curr->next;
    
    
    
}


void lastnode()
{
    DLLNode*curr=list;

     while(curr->next != NULL)
    {
        curr=curr->next;
    }

}

void RecursiveDisplayB(DLLNode* i)   // not  correct
{
    DLLNode*curr;
    
    
    if (curr==NULL )
    {
        return;
    }


    cout<<curr->data<<endl;
    
    RecursiveDisplayB(curr->prev);

    // curr=curr->next;
}




int main()
{
    int choice, val,num; 
    DLLNode* temp;
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert \n2. Display \n3. Recursive Display Forward \n4. Recursive Display Backward\n5. Exit \n";
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

            case 3:
                RecursiveDisplayF(list);
                break;


            case 4:
                lastnode();
                RecursiveDisplayB(list);
                break;

      
            case 5:
                exit(0);
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}