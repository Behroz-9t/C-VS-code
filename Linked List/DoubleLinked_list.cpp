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




void searching(int value) // same as the single linked list
{
    DLLNode*curr=list;
    int index=0;

    if(curr==NULL)
    {
        cout<<"List is empty, deletion not possible"<<endl;
        return;
    }

    while(curr!=NULL)
    {
        if(curr->data==value)
        {
            cout<<"Value "<<value<<" found at index: "<<index<<endl;
            return;
        }
        curr=curr->next;
        index++;
    }
    cout<<"Value not found: "<<value<<endl;
 
    
}




void Delete(int value)
{
    DLLNode*curr=list;
    DLLNode*prev=NULL;
    
    if(curr==NULL)
    {
        cout<<"List is empty, deletion not possible"<<endl;
        return;
    }

    if(value==list->data) //for the first element
    {
        

        if (list->next == NULL) // Case 1: when there is only one node 
        {
            free(list); // directly frees the list and NULLs the list
            list = NULL;
            cout << "Value deleted: " << value << endl;
            return;
        }
        
        else{

            list=list->next; // list pointer updated to the next elemnt

            list->prev=NULL; // (crucial move) updates the backward link by making the new first element's prev NULL

            free(curr);
            cout<<"Value deleted: "<<value;
            return;

        }
    }
    curr=list->next; // updates the curr to the list's next element
    prev=list;

    while (curr->next!=NULL)
    {
        if(value==curr->data)
        {
            prev->next=curr->next; // in the prev's next assigns the curr's next (links the prev element to the (next to next) elemnt)

           
            curr->next->prev=curr->prev; // assigns the curr's next's prev to curr's prev ( joins present(element to be deleted's) next elmnt's prev to the present's prev ) maintain the backward link of the element before the deletion.
            free(curr);
            cout<<"Value deleted: "<<value<<endl;
            return;
        }
        
        
        prev=curr;
        curr=curr->next;
    }
    cout<<"Value not found: "<<value<<endl;
}




int main()
{
    int choice, val,num; 
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert \n2. Display \n3. Search \n4. Delete\n5. Exit \n";
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
                cout << "Enter value to search: ";
                cin >> num;
                searching(num);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> num;
                Delete(num);
                break;

            case 5:
                exit(0);
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}