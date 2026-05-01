#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack
{
    int data;
    stack*next;
    
};

stack*top=NULL;


void push(int value)
{
    stack*temp; 
    temp=(stack*)malloc(sizeof(stack));  
    temp->data=value; 
    
    temp->next=top;   // assigns top to temp's next 
                      // top is now currently at the bottom
    top=temp;         // pushes the top upward

}

void pop ()
{
    if (top == NULL)
    {
        cout<<"the stack is in underflow condition";
        return ;
    }

    stack * temp= top;
    // cout<<"the value has been popped"<<top->data;
    top=top->next;
    free(temp);

    
}


void display()
{
    stack * curr=top;
    if (top==NULL)
    {
        cout<<"Stack is empty";
        return;
    }
    while(curr!=NULL)
    {
            
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    
}




int main()
{
    int choice, val,num; 
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. push \n2. pop \n Exit \n";
        cout << "Enter choice: ";
        cin >> choice; 
        
        switch(choice) 
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                push(val);
                break;
            
      

            case 2:
                pop();
                break;


            case 3:
                display();
                break;
            // case 3:
            //     cout << "Enter value to search: ";
            //     cin >> num;
            //     searching(num);
            //     break;

            // case 4:
            //     cout << "Enter value to delete: ";
            //     cin >> num;
            //     Delete(num);
            //     break;

            // case 5:
            //     exit(0);
            //     break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;

}
