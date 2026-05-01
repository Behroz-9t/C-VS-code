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



int listlength()
{
    Node* curr= list;
    int count=0;
    
    while(curr->next != NULL)
    {
        curr=curr->next ;
        count++;
    }
    return count;
}

// Mid paper Question 
// custom display to print the node from the end if input 3
// then the fnc should output 8 
// without using last or prev 
// cannot use the count or index pointer either 
// cannot modify the insert fnc 

// list --> 1 --> 2 --> 3 --> 4 --> 5 --> 6 --> 7 --> 8 --> 9 --> 10 --> NULL

// Takes the input and display the nodes data from the end
void customDisplay(int i)
{
    Node* curr= list;
    int length = listlength();
    
    for (int j=1; j<(length-i);j++)
        {
            if (curr->next!=NULL)
            {
                curr=curr->next;
            }
        }
    cout<< curr->data;
}

void reversePrint(Node* head, int &n)
{
    if(head == NULL)
    return;

    reversePrint(head->next, n);

    if(--n == 0)
    {
        cout<<head->data;
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
                cout << "Enter value from the end to display the element of LL: ";
                cin >> num;
                customDisplay(num);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> num;
                reversePrint(list,num);
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

