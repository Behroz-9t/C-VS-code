#include <iostream>
#include<stdlib.h>
using namespace std;

struct tree
{
    int data;
    tree*left=NULL;
    tree*right=NULL;
};



tree* insert(tree*root,int value)
{
    if (root==NULL)
    {
        tree* temp;
        temp=(tree*)malloc(sizeof(tree));
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    
    
    cout<<root->data;
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
    
}


void LNR (tree*root)
{
    // if (root==NULL)
    // {
    //     cout<<"The tree is empty";
    //     return ;
    // }
    
    // LNR(root->left);  //L
    // cout<<root->data<<endl; //N
    // LNR(root->right); //R




    if (root!=NULL)
    {

        LNR(root->left);
        cout<<root->data<<endl;
        LNR(root->right);
    }
    
}
void LRN (tree*root)
{
    // if (root==NULL)
    // {
    //     cout<<"The tree is empty";
    //     return ;
    // }
    
    // LNR(root->left);  //L
    // cout<<root->data<<endl; //N
    // LNR(root->right); //R




    if (root!=NULL)
    {

        LNR(root->left);
        LNR(root->right);
        cout<<root->data<<endl;
    }
    
}



void NLR (tree*root)
{
    // if (root==NULL)
    // {
    //     cout<<"The tree is empty";
    //     return ;
    // }
    
    // LNR(root->left);  //L
    // cout<<root->data<<endl; //N
    // LNR(root->right); //R




    if (root!=NULL)
    {

        cout<<root->data<<endl;
        LNR(root->left);
        LNR(root->right);
    }
    
}


tree* mini(tree*root)
{
    while(root->left!=NULL )

    {
        root=root->left;
  
    }
    return root;
} 



tree* Delete(tree*root,int value)
{

    if (root==NULL) // cond:1 if there is no value in the tree
    {
        cout<<"Reached at the end";
        return NULL;
    }

    if (value>root->data) // recursive checks to check if the value is bigger than root  
        {
            root->right=Delete(root->right,value); // if the value is bigger than the root then calls the delete func here and in further checks we are returning the temp which actually holds the address to the next leaf node to link it to the previous root right
        }

    else if(value<root->data) // or value is smaller than the root
        {
            root->left=Delete(root->left,value);
        }

    else 
    {
        if (root->left==NULL && root->right==NULL) // cond:2 when the tree only consists of one parent node and the two other child node are NULL
            {
            
                cout<<"The value to delete: "<<root->data;
                free(root);
                return NULL;
            }
            
        else if (root->left==NULL) // cond:3a when the tree of one parent and two child leaf nodes if left is null
            {
            tree*temp=root->right;
            free(root);
            // cout<<temp->data;
            return temp;
            }
        
        else if (root->right==NULL) // cond:3b  if right is null
            {
                tree*temp=root->left;
                free(root);
                cout<<temp->data;
                return temp;
            }
        
        
        else // cond 4a : else the cond for the multiple parent and multiple child tree
        {
                tree* temp=mini(root->right); // from the right side we have to pick the smallest from the left and replace it by the root node
                // int* var=root->data;
                root->data=temp->data; // places temp data into root data
                // temp->data=var;
                root->right=Delete(root->right,temp->data); // --------------------???????
                // free(temp);
        }
        
    }
    // cout<<root->left->data;
    return root; // --------------------??????
}









int main()
{
    int choice, val,num; 
    tree * root=NULL;
    
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert \n2. LNR \n3. NLR \n4. Delete \n3. LRN \n";
        cout << "Enter choice: ";
        cin >> choice; 
        
        switch(choice) 
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root=insert(root,val); //------------
                break;
                
            case 2:
                LNR(root);
                break;
            case 3:
                NLR(root);
                break;
                
            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                root=Delete(root,val);
                break;
                
            case 5:
                    LRN(root);
                    break;
                
        }
    }
    return 0;

}