#include <iostream>
#include<stdlib.h>
#include<cctype>
using namespace std;

struct stack
{
    char data;
    
    stack*next;
    
};

stack*top=NULL;
char listno[12]={'*','/','%', '+', '-',  '<','>','&','!','|','(',')'};
char postfix[100];
                      
                      
int ind=0; // how is the index working for the different functions ???????







void push(int value)
{
    stack*temp; 
    temp=(stack*)malloc(sizeof(stack));  
    temp->data=value; 
    
    temp->next=top; 
    top=temp;

}



void pop ()
{
    if (top == NULL){
        cout<<"the stack is in underflow condition";
        return ;
    }

    stack * temp= top;
    // cout<<"the value has been popped"<<top->data;
    top=top->next;
    free(temp);

    
}


int precedence(char value)
{
    switch (value)
    {
    // case '(':
    //     return -1;
    //     break;
    // case ')':
    //     return -1;
    //     break;
    case '*':
        return 6;
        break;
    case '/':
        return 6;
        break;
    case '%':
        return 6;
        break;
    case '+':
        return 5;
        break;
    case '-':
        return 5;
        break;
    case '<':
        return 4;
        break;
    case '>':
        return 4;
        break;
    case '!':
        return 3;
        break;
    case '&':
        return 2;
        break;
    case '|':
        return 1;
        break;
    
    default:
        return 0;
        break;
    }
}


// void braces(char value)
// {

// }



void comparison(int value)
{

    for (size_t i = 0; i < 12; i++)
    {
        if (value==listno[i] )
        {   
         
            if (top ==NULL )
            {
                push(value);
                return;
            }
            
            if (value=='(')
            {
                push (value);
                return;
                
            }


            if (top->data=='(')

            {
                push (value);
                return;
            }





            if ( precedence(top->data) < precedence(value))
            {
                push(value);
                return;
            }

           
            if ( precedence(top->data)>=precedence(value))
            {

                while (top!=NULL && precedence(top->data)>=precedence(value))
                
                    {
                        postfix[ind]=top->data;
                        ind++;
                        pop();
                        
                        
                    }
                    
                push(value);
                return;
                
            }
            
            
            if (value==')')
            {
                while (top->data!='(')
                {
                    if (value=='(')
                    {
                        pop();
                        return;
                    }

                    else
                    {
                    
                        postfix[ind]=top->data;
                        pop();
                        ind++;
                    }

                }
                
            }
            
                
        }
            
        
    }
   

        postfix[ind]=value;
        ind++;
    

    

}



    
void emptyStack()
{
    
    while (top!=NULL )
        {
            // if (top->data!= '(' || top->data!= ')')
            
            postfix[ind]=top->data;
            pop();
            ind++;
        }
    
}
    



void display()
{
    stack * curr=top;
    if (top==NULL)
    {
        cout<<"\nStack is empty\n";
        return;
    }
    while(curr!=NULL)
    {
            
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    
}

int evaluate ()
{
    int stack [100];
    int L= -1;
    for (int i = 0 ; i <ind;i++)
    {
    char c = postfix[i];

    if(isdigit(c)) 
    {
        stack[++L]= c - 48 ;
    } 
 

    else{

        if (L < 1) 
      {
        cout <<"The postfix is incorrect!" << endl ;
        return 0; 
      }
      
      int b = stack[L--];
      int a = stack[L--];

      int result = 0 ;

      switch(c) 
      {
        case '+' :
            result = a + b;
            break;
        case '-':
            result = a - b ;
            break;
        case '*':
            result = a * b ;
            break;
        case '/':
            result = a / b;
            break;
        case '%':
            result = a % b ;
            break ;
        default:
            cout << "Invalid operator" ; 
            return 0;
        }
        stack[++L]=result;
    }
}
return stack[L];
}


// int main()
// {
//     // int n =7;
//     // char array[n]={'a', '+','(','b','*','c' ,')'};

//     // int n =9;
//     // char array[n]={ 'A', '*', '(', 'B', '+', 'C', ')', '*', 'D' };

//     // int n =7;
//     // char array[n]={'a', '+','b','*','c','-','d'};


//     int n =7;
//     char array[n]={'1', '+','2','*','3','-','4'};
    
	
// 	while (true){
//     	char value;
//     	int choice;
//     	cout << "\n1.Enter value\n2.Stack display\n3.Postfix\n4.Evaluate the expression\n";
//         cout<< "Enter choice:";
    	
//     	cin>>choice;
//     	switch(choice)
//         {
//     		case 1:
//                 for (size_t j = 0; j < n; j++)
//                 {   
//                     value=array[j];
//                     comparison(value);
//                 }
//                 cout<<"The function executed sucessfully !!\n";
//                 break;

//             case 2:
//                 display();
//                 break;  

//             case 3:
//                 if (ind==0)
//                 {
//                     cout<<"The postfix is currenty empty";
//                 }
//                 else{

//                     emptyStack();

//                     for (int i=0;i<n;i++)
//                     {
//                         cout<<postfix[i]<<",";
//                     }
//                 }
//                 cout<< "\n";
//             	break;


//             case 4:
//                 cout<<"The expression result: "<<evaluate()<<endl;
//                 break;
// 		}
// 	}

// }









int main()
{
    int n = 7;
    char array[n] = {'1', '+','2','*','3','-','4'};

    int choice;

    while (true)
    {
        cout << "\n1. Convert to Postfix\n2. Display Stack\n3. Show Postfix\n4. Evaluate\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // RESET before converting
            top = NULL;
            ind = 0;

            for (int j = 0; j < n; j++)
            {
                comparison(array[j]);
            }

            emptyStack(); // VERY IMPORTANT
            cout << "Conversion done!\n";
            break;

        case 2:
            display();
            break;

        case 3:
            if (ind == 0)
            {
                cout << "Postfix is empty\n";
            }
            else
            {
                cout << "Postfix: ";
                for (int i = 0; i < ind; i++)   // FIXED
                {
                    cout << postfix[i] << " ";
                }
                cout << endl;
            }
            break;

        case 4:
            if (ind == 0)
            {
                cout << "First convert expression!\n";
            }
            else
            {
                cout << "Result: " << evaluate() << endl;
            }
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}








