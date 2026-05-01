#include<iostream>
#include<stdlib.h>
using namespace std;

struct CLLNode
{
    int data;
    CLLNode * next; 
    CLLNode*prev;

};

CLLNode*list=NULL;


void insert(int value)
{
    CLLNode*temp;
    temp=(CLLNode*)malloc(sizeof(CLLNode));
    temp->data=value;


    if (list==NULL)
    {
        list = temp;
        temp->next=list;
        return;
    }

    
    CLLNode*curr=list;
    while(curr->next!=list)
    {
        curr=curr->next;

    }
    curr->next=temp;
    temp->next=list;
}




void search(int value)
{
    CLLNode*curr=list;

    if( value == curr->data)
    {
        cout<<"value found";
    }
    curr=curr-> next;


    while (curr!=list)
    {

        if (curr->data==value)
        {
            cout<<"Value found";
            return;
        }
        curr=curr->next;
    }
    cout<<"value not found";

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


void Delete(int value)
{
    CLLNode*curr=list;
    CLLNode*temp=list;
    
    
    if(value==list->data)
    {
        
        while(curr->next!=list)
        {
            curr=curr->next;
            
        }
        
        curr->next=list->next;
        list=list->next;
        free(temp);
        return;
        
    }
    curr=curr->next;
    CLLNode*prev=list;

    while(curr!=list)
    {
        if (value==curr->data)
        {
            prev->next=curr->next;
            temp=curr;
            free(temp);
            cout<<prev->next->data;
            return;
        }
        curr=curr->next;
        prev=prev->next;
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
                search(num);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> num;
                Delete(num);
                break;

            // case 5:
            //     exit(0);
            //     break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;

}