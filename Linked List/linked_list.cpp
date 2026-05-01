#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node * next;  //Pointer to next node

};

Node*list=NULL;   // Global pointer to the head of the list 
                  // (It sits outside the function (global scope) and holds the address of the very first node).

void insert(int value)
{
    Node*temp; // temp of type node is declared
    temp=(Node*)malloc(sizeof(Node)); // temp basically stores the node type of address which we tells malloc to allocate through the sizeof func 
    temp->data=value; // the value is assigned to the temp's data
    temp->next=NULL; // initially becuase it is a single linked list, the next of ht last elemnt is set to NULL

    if (list==NULL) // if the list is NULL which is NULL initially it assigns the list to temp 
    {
        list=temp;  //so now temp and list are both pointing to the first elemnt
    }
    else // if there are already elemnts in the list 
    {
        Node*curr=list; // introduced the new pointer curr whch also points to list
        while(curr->next!=NULL) //while executes till the curr's next becomes NULL
        {
            curr=curr->next; // making the curr's next NULL so that the curr is the last elemnt of the list which we want 
        }
        curr->next=temp; // here we found the curr's next is NULL so the curr is the last elemnt, Now we assign the curr's next to temp,temp which holds the data we assigned just now and temps next is NULL as we did before afte assigning the data
    }
}


void searching(int value)
{
    Node*curr=list;
    while(curr!=NULL)
    {
        if(curr->data==value)
        {
            cout<<"Value found: "<<value<<endl;
            return;
        }
        curr=curr->next;
    }
    cout<<"Value not found: "<<value<<endl;
 
    
}

void display()
{
    Node*curr=list;
    if (list!=NULL)
    {
        while(curr!=NULL)
        {
            
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    else
    {
        cout<<"List is empty"<<endl;
    }
}

void Delete(int value)
{
    Node*curr=list;
    Node*prev=NULL;
    
    if(curr==NULL)
    {
        cout<<"List is empty, deletion not possible"<<endl;
        return;
    }

    if(value==list->data) // scenario we want to delete first elemnt
    {
            
            
        list=list->next;
        free(curr);
        cout<<"Value deleted: "<<value;
        return;
    }
    curr=list->next;
    
    prev=list;
    
    while (curr!=NULL)
    {
        if(value==curr->data)
        {
            prev->next=curr->next;

            free(curr);
            cout<<"Value deleted: "<<value<<endl;
            return;
        }
        else{
            cout<<"Value not found: "<<value<<endl;
        }
        prev=curr;
        curr=curr->next;
    }

   
    
    
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
    return 0;

}

