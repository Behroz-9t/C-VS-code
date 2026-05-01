#include <iostream>
#include <stdlib.h>
using namespace std;


struct tree
{
    int data;
    int height=0;
    tree*left=NULL;
    tree*right=NULL;
};

// to get height of a node
int getHeight(tree* node) 
{
    if (node == NULL)
    {
        return -1;    //beause furter we are using this func: maximum() + 1 so the -1 + 1 becomes 0
    }
    else
    {
        return node->height;
    }
}

//  to find maximum of two integers
int maximum(int a, int b) 
{
    if (a > b)
    {
        return a;

    } 
    else
    {

        return b;
    }
}

// ROTATE RIGHT
tree* rotateRight(tree* curr) 
{
    tree* temp = curr;
    curr = curr->left;
    tree* temp2 = curr->right;
    
    curr->right = temp;
    temp->left = temp2;

    temp->height = maximum(getHeight(temp->left), getHeight(temp->right)) + 1;
    curr->height = maximum(getHeight(curr->left), getHeight(curr->right)) + 1;

    return curr;
}

// ROTATE LEFT
tree* rotateLeft(tree* curr)
 {
    tree* temp = curr;
    curr = curr->right;
    tree* temp2 = curr->left;
    
    curr->left = temp;
    temp->right = temp2;

    temp->height = maximum(getHeight(temp->left), getHeight(temp->right)) + 1;
    curr->height = maximum(getHeight(curr->left), getHeight(curr->right)) + 1;

    return curr;
}

// ROTATE LEFT RIGHT
tree* rotateLeftRight(tree* curr) 
{
    curr->left = rotateLeft(curr->left);
    return rotateRight(curr);
}

// ROTAE RIGH LEFT
tree* rotateRightLeft(tree* curr) 
{
    curr->right = rotateRight(curr->right);
    return rotateLeft(curr);
}


tree* insert(tree*root,int value)
{
    if (root==NULL)
    {
        tree* temp;
        temp=(tree*)malloc(sizeof(tree));
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=0;

        return temp;
    }
    
    cout<<root->data;

    // cond: if value is smaller than current node
    if (value < root->data) 
    {
        root->left = insert(root->left, value);
        
        // Check if left is balanced
        if ((getHeight(root->left) - getHeight(root->right)) == 2) 
        {
            if (value < root->left->data)
            {
                root = rotateRight(root);       // LeftLeft case  

            }
            else
            {
                root = rotateLeftRight(root);   // Left Right case

            }
        }
    } 
    // cond: if value is larger than current node
    else if (value > root->data) 
    {
        root->right = insert(root->right, value);
        
        // Check if righ is balanced
        if ((getHeight(root->right) - getHeight(root->left)) == 2)
         {
            if (value > root->right->data)
            {

                root = rotateLeft(root);        // Riht Right case
            }
            else
            {
                root = rotateRightLeft(root);   // Right Lef case
                
            }
        }
    }
    
    // Update heigt the current root
    root->height = maximum(getHeight(root->left), getHeight(root->right)) + 1; // every node's height is updated here
    
    return root;
}


// fetches the smallest number from the root's right
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
    
    // cond:1 if there is no value in the tree
    if (root==NULL) 
    {
        cout<<"Reached at the end";
        return NULL;
    }

    // cond:2 if value is greater than the root
    if (value> root-> data) 
    {
        root->right=Delete(root->right , value);

        // we have to check if the root is not null
        if (root != NULL)
        {
            root->height = maximum(getHeight(root->left), getHeight(root->right)) + 1;

        }

        // Check if right is balanced
        if ((getHeight(root->left) - getHeight(root->right)) == 2) 
        {
            
            // Look at the Left Child's heights to decide the rotation
            // if root left's left height is equal or greater than left's right do right rotate
            if (getHeight(root->left->left) >= getHeight(root->left->right)) 
            {
                root = rotateRight(root);       // Left-Left case
            } 
            
            // if root left's left height is less than left's right do right rotate
            else 
            {
                root = rotateLeftRight(root);   // Left-Right case
            }
        }
        
        
        
    }
    
    // cond:3 if value is smaller than the root
    else if (value<root->data) 
        {
            root->left=Delete(root->left,value);

            
            // we have to check if the root is not null
            if (root != NULL)
            {
                root->height = maximum(getHeight(root->left), getHeight(root->right)) + 1;

            }

            // Check if right is balanced
            if ((getHeight(root->right) - getHeight(root->left)) == 2) 
            {
                
                // Look at the Left Child's heights to decide the rotation
                
            if (getHeight(root->right->right) >= getHeight(root->right->left)) 

                {
                    root = rotateLeft(root);        // Right-Right case
            
                }
                 else
                {
                    root = rotateRightLeft(root);   // Right-Left case
                }
            }
        }


    // cond:4 This is where the root becomes equal to the value
    else 
    {
        // cond:4a when the root is the last node which is to be deleted and the two other child node are NULL
        if (root->left==NULL && root->right==NULL) 
            {
            
                cout<<"The value to delete: "<<root->data;
                free(root);
                return NULL;
            }

        // cond:4b when the root note's left is NULL it check right only
        else if (root->left==NULL) 
            {
            tree*temp=root->right;
            free(root);
                // cout<<temp->data;
            return temp;
            }

        // cond:4c when the root note's right is NULL it check left only
        else if (root->right==NULL) 
            {
                tree*temp=root->left;
                free(root);
                cout<<temp->data;
                return temp;
            }

        // cond 4d : else the cond for the multiple parent and multiple child tree
        else 
        {
                // from the right side we have to pick the smallest from the leftmost and replace it by the root node
                // fetches the smallest number from the root's rght
                tree* temp=mini(root->right); 
                
                // places smallest number from the right into root data
                root->data=temp->data; 
                

                // Deletes that duplicate number from the root right's left most smallest number which is being replaced by the number which is to be deleted 
                root->right=Delete(root->right,temp->data); 

                if (root != NULL)
                {

                    root->height = maximum(getHeight(root->left), getHeight(root->right)) + 1;
                }

                // CHECK BALANCE 
                
                if ((getHeight(root->left) - getHeight(root->right)) == 2) 
                {
                    
                    if (getHeight(root->left->left) >= getHeight(root->left->right)) 
                    {
                        root = rotateRight(root);       // Left-Left case
                    } 
                    else 
                    {
                        root = rotateLeftRight(root);   // Left-Right case
                    }
                
                }
        }

    }

    // every node's height is updated here
    if (root != NULL)
        {

            root->height = maximum(getHeight(root->left), getHeight(root->right)) + 1;  
        }
 

    return root;
}

void LNR (tree*root)
{
    if (root!=NULL)
    {
        LNR(root->left);
        cout<<root->data<<endl;
        LNR(root->right);
    }
}

void LRN (tree*root)
{
    if (root!=NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout<<root->data<<endl;
    }
}

// void NLR (tree*root)
// {
//     if (root!=NULL)
//     {
//         cout<<root->data<<endl;
//         NLR(root->left);
//         NLR(root->right);
//     }
// }

int main()
{
    int choice, val; 

    //root node of the tree
    tree * root=NULL; //120
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert \n2. LNR \n3. Delete\n4. LRN\n";
        cout << "Enter choice: ";
        cin >> choice; 
        
        switch(choice) 
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root=insert(root,val);
                break;
                
            case 2:
                LNR(root);
                break;


            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                root=Delete(root,val);
                break;
                

            case 4:
                    LRN(root);
                    break;
                  
                    
            // case 3:
            //     NLR(root);
            //     break;
                
        }
    }
    return 0;
}