#include<iostream>
#include<stdlib.h>
using namespace std;

struct CLLNode
{
    int data;
    CLLNode * next;  //Pointer to next node
    CLLNode*previous;

};

CLLNode*list=NULL;   // Global pointer to the head of the list 
                     // (It sits outside the function (global scope) and holds the address of the very first node).

void insert(int value)
{
    CLLNode*temp;
    temp=(CLLNode*)malloc(sizeof(CLLNode));
    temp->data=value;

    
    if (list==NULL) // if the list is NULL add the data and point it to itself
    {
        list=temp;
        temp->next=list; //pointing to itself
    }
    else
    {
        CLLNode*curr=list;
        while(curr->next!=list)
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=list; //pointing to head
    }
}


void searching(int value)
{
    CLLNode*curr=list;

    if(list==NULL)
    {
        cout<<"List is empty, search not possible"<<endl;
        return;
    } 

    if(value==curr->data) // finding the first elemnt separtely and updating the curr to the 2nd elemnt so that our while loop donot fails just as in display
    {

        cout<<"Value found "<<value;
        return;
    }
    curr=curr->next;

    while(curr!=list) // finding the rest elemnts the old method
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


void Delete(int value)
{
    CLLNode*curr=list;
    CLLNode*previous=list;
    CLLNode*last=list;

    if(list==NULL)
    {
        cout<<"List is empty, deletion not possible"<<endl;
        return;
    }

    if(value==list->data) // for the first element of the list 
    {
        if (list->next == list) // Case 1: when there is only one node in the circular linked list
        {
            
            free(list); // directly frees the list and NULLs the list
            list = NULL;
            cout << "Value deleted: " << value << endl;
            return;
        }
        else  // Case 2: When there are more than one elements in a list
        {
            while(last->next!=list)  // we introduced a new pointer variable (last) which keeps track of the last element because in additional to the single linked list we also have to join the last element to the (new) first element after the deletion of the first element
            {       // the next is iniatially pointing to the start of the list so we move it further to the last element
                last=last->next;  // by repeatedly calling the next 
            }


            last->next = list->next;  // once we get the last element we assign the list's next to the last's next (basically we store the address of the list's next element which is (2nd element of the list) where we want to connect the list to, to the last's next, so last element now has gotten the address of the 2nd element of the list and is connected to 2nd element )
            list=list->next; // until now only the last element is connected to the 2nd elemnt, We also have to connect the list to 2nd element so we assign the list to the list's next element
            free(curr);  // now at last we can free the current which was still pointing to the first elemnt so it gets completly deleted
            cout<<"Value deleted: "<<value<<endl;
            return;
        }
        
       
    }
    curr=list->next; // Initializes the curr to list next element
    previous=list; // previous to the list
    
    while (curr!=list) // now the while loop runs beacuse initially the curr is not pointing to the list first element
    {
        if(value==curr->data)
        {
            previous->next=curr->next;
            free(curr);
            cout<<"Value deleted: "<<value<<endl;
            return;
        }
        curr=curr->next;  // for when the curr's data is not equal to the value and if condition is executed, then the curr updates to next elemnt and the previous updates with respect to it.
        previous=previous->next;
    }
    
}



void display()
{
    CLLNode*curr=list;

    
    if (list!=NULL)
    {
        cout<<curr->data<<" "; // for printing the first element of the list and then updating the current next
        curr=curr->next;       // update curr to 2nd elemnt
                               // we did this so that our next while conditions remains satisfied, otherwise it will not be executed 
                               // because the curr is intially pointing to the list
        while(curr!=list) 
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

