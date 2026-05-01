#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node * next;  
    
};

Node ht[5];




void init()  // with flag 
{
    for (int i = 0; i < 5; i++) 
    {
        ht[i].data= -1;  // -1 means the slot is empty
    }
}






void insert(int value)
{
    int size=5;
    int ind = value % size;

    if (ht[ind].data == -1)
    {

        ht[ind].data=value;
        return;

    }
    else
    {
        Node*temp;
        temp= (Node*)malloc(sizeof(Node));
        temp->data=value;
        temp->next=NULL;

        Node*curr=ht[ind].next;
        
        if (curr==NULL)
        {
            ht[ind].next=temp;
            
        }
        
        else
        {
            while(curr->next!=NULL)
            {
                curr=curr->next; 
            }
            curr->next=temp;
        }

    }
}


void display()
{
    
    
    for (int i=0;i<5;i++)
    {
        if (ht[i].data==-1)
        {
            cout<<"Empty"<<endl;
        }
        
        // if (ht[i].next==NULL)
        // {
        //     cout<<ht[i].data<<endl;
        // }

        else
        {
            Node*cur;
            cout<<ht[i].data;
            cur=ht[i].next;
            cout<<" ";
            while(cur !=NULL)
            {
                cout<<cur->data;
                cout<<" ";
                cur=cur->next;
            }
            cout<<"\n";
            
        }
        
       
    }
}





void search(int value)
{
  for ( int i =0; i<5 ; i++)
  {
    if (ht[i].next==NULL)
    {
        
        if (ht[i].data==value)
        {

            cout<<"the number is found";
        }

    
    }
    else{
        Node * found =ht[i].next;

        if (ht[i].data==value)
        {
            cout<<"the number is found";
            return;
        }
        while(found!=NULL)
        {
            if (found-> data==value){

                cout<<"the number is found";

            }
            found=found->next;
        }
    }

  }

}



int main()
{
    int choice, val,num; 
    init();
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert \n2. Display \n3. Search \n";
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
                    cin >> val;
                    search(val);
                    break;
        }
    }
    return 0;

}





