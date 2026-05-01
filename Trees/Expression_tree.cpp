#include<iostream>
#include<stdlib.h>
#include<cctype>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char value) 
{
    Node* temp = new Node();
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node* stack[100];
int top = -1;

void push(Node* node) 
{
    stack[++top] = node;
}

Node* pop() {
    return stack[top--];
}

int isOperator(char c) 
{
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

Node* buildTree(char postfix[]) 
{
    for (int i = 0; postfix[i] != '\0'; i++) {
        
        if (isalnum(postfix[i])) {
            push(createNode(postfix[i]));
        }
        else if (isOperator(postfix[i])) {
            Node* right = pop();
            Node* left = pop();

            Node* temp = createNode(postfix[i]);
            temp->left = left;
            temp->right = right;

            push(temp);
        }
    }
    return pop(); // root
}

// inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

int main() {
    char postfix[] = "AB+C*";
    Node* root = buildTree(postfix);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}