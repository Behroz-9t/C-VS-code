#include<iostream>
#include<stdio.h>

using namespace std;

struct edge;

struct vertex
{
    char data;
    vertex*vnext;
    edge*edgelist;
    bool visited;

    vertex* parent;
    
};

struct edge
{
    int weight;
    edge*enext;
    
    vertex*v;

};

vertex*graph=NULL;




struct queue
{
    vertex*data;
    queue*next;
}; 

queue*front=NULL;
queue*rear= NULL;

void Enqueue(vertex* value)
{
    queue*temp;
    temp=(queue*)malloc(sizeof(queue));
    temp->data=value;
    temp->next=nullptr;

    if (front ==NULL & rear == NULL) 
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp; 
        rear=temp;  
    }

}



vertex* Dequeue()
{
    queue*curr=front;
   
    
    if(front==NULL) // cond 1 queue is empty
    {
        cout<<"List is empty, deletion not possible"<<endl;
        return 0;
    }

    if (front==rear) // cond 2 only one element present
    {
        vertex* tmp = curr->data;
        free (curr);
        rear=NULL;
        front=NULL;
        return tmp;
    }
    
    
    else // cond 3 more than one element
    {
        vertex* tmp = curr->data;
        front=front->next;
        free(curr);
        return tmp;
    }
}






struct stack
{
    vertex* data;
    stack*next;
    
};

stack*top=NULL;


void push(vertex* value)
{
    stack*temp; 
    temp=(stack*)malloc(sizeof(stack));  
    temp->data=value; 
    
    temp->next=top;   // assigns top to temp's next 
                      // top is now currently at the bottom
    top=temp;         // pushes the top upward

}



vertex* pop ()
{
    vertex*value;

    if (top == NULL)
    {
        cout<<"the stack is in underflow condition";
        return 0;
    }

    stack * temp= top;
    value=temp->data;
    // cout<<"the value has been popped"<<top->data;
    top=top->next;

    free(temp);
    return value;
}





// int arrmat[5][5];


void AddVertex (char value)
{
    vertex*temp;  // temp for the courses
    temp=(vertex*)malloc(sizeof(vertex));
    temp->data=value; 
    temp->vnext=NULL;  // 
    temp->visited=false;
    
    temp->edgelist=NULL; // 

    if (graph==NULL)
    {
        graph=temp;
    }
    else
    {
        vertex*curr=graph;
        while(curr->vnext!=NULL)
        {
            curr=curr->vnext;
        }
        curr->vnext=temp;
    }


}

void removeAllOcc(char value)
{
    vertex*curr=graph;

        while (curr!=NULL)
        {
            edge*ecurr=curr->edgelist;
            edge*prev1;
            while(ecurr!=NULL)
            {
                if (value==curr->edgelist->v->data)
                {
                    curr->edgelist=curr->edgelist->enext;
                    free(ecurr);
                    break;
                }
                prev1=curr->edgelist;
                ecurr=ecurr->enext;
                while(ecurr!=NULL)
                {
                    if (value==ecurr->v->data)
                    {
                        prev1->enext=ecurr->enext;
                        free(ecurr);
                        break;

    
                    }
                    prev1=ecurr;
                    ecurr=ecurr->enext;
                }
                
                ecurr=ecurr->enext;
            }
            curr=curr->vnext;
        }
    return;

}


void RemoveVertex(char value)
{
    vertex*curr=graph;
    vertex* prev;

    while (curr!=NULL)
    {
        if (value==curr->data)
        {
            graph=graph->vnext;
            edge*ecurr=curr->edgelist;

            while(ecurr!=NULL)
            {
                curr->edgelist=curr->edgelist->enext;
                free(ecurr);
                ecurr=curr->edgelist;
                
            }
            free(curr);
            return;
        }

        prev=graph;
        curr=curr->vnext;

        while (curr !=NULL)
        {
            if (value==curr->data)
            {
                prev->vnext=curr->vnext;
                edge* ecurr = curr->edgelist;

                while(ecurr!=NULL) 
                {
                    curr->edgelist=curr->edgelist->enext;  

                    free(ecurr);  

                    ecurr= curr->edgelist;  
                    
                }
                free(curr); 
                
            }
            prev=curr;
            curr=curr->vnext;
        }

        removeAllOcc(value);

    }
    
}





vertex* GiveAddress(char value)
{
    vertex*curr=graph;
    vertex*address;

    while (curr!=NULL)
    {
        if (value==curr->data)
        {
            return curr;
        }
      curr=curr->vnext;
    }

    cout<<"The vertex doesnot exists"<<endl;
    return 0;
    
}


void AddEdge(char vert1,char vert2)
{
    vertex*curr=graph;
    vertex*curr2=graph;
    
    edge*ecurr1;
    edge*ecurr2;

    while(curr!=NULL)
    {
    
        if (vert2==curr->data)
        {
            vertex*address1=GiveAddress(vert2);

            while (curr2!=NULL)
            {
                if (vert1==curr2->data)
                {
                    
                    edge*temp;
                    temp=(edge*)malloc(sizeof(edge));
                    temp->v=address1;
                    temp->enext=NULL;
                    temp->weight=0;
                    
                   
                    if (curr2->edgelist==NULL)
                    {
                        curr2->edgelist=temp;
                    }
                    else
                    {
                        ecurr1=curr2->edgelist;
                        while(ecurr1->enext!=NULL)
                        {
                            ecurr1=ecurr1->enext;
                        }
                        ecurr1->enext=temp;

                    }
                }
                curr2=curr2->vnext;
                
            }

            vertex*address2=GiveAddress(vert1);

            edge*temp2;
            temp2=(edge*)malloc(sizeof(edge));
            temp2->v=address2;
            temp2->enext=NULL;
            temp2->weight=0;

            if (curr->edgelist==NULL)
            {
                curr->edgelist=temp2;
            }
            else
            {
                ecurr2=curr->edgelist;
                while(ecurr2->enext!=NULL)
                {
                    ecurr2=ecurr2->enext;
                }
                ecurr2->enext=temp2;

            }

        }
        curr=curr->vnext;
    }
}


void RemoveEdge(char vert1,char vert2)
{
    vertex*curr=graph;
    vertex*curr2;

    edge*ecurr;
    edge*ecurr2;

    edge*prev=NULL;
    edge*prev2=NULL;

    while (curr!=NULL)
    {
        if (vert1==curr->data)
        {
            ecurr=curr->edgelist;
            while(ecurr!=NULL)
            {
                if (vert2==ecurr->v->data)
                {
                    
                    curr2=ecurr->v;
                    ecurr2=curr2->edgelist;
                    while(ecurr2!=NULL)
                    {

                        if (vert1==ecurr2->v->data)
                        {
                            if (prev2==NULL)
                            {
                                curr2->edgelist=curr2->edgelist->enext;
                                    
                            }
                            else
                            {
                                prev2->enext=ecurr2->enext;
    
                            }
                                
                            free(ecurr2);
                            break;
                        }
                        prev2=ecurr2;
                        ecurr2=ecurr2->enext;
                    }

                        
                    
                    if (prev==NULL)
                    {
                        curr->edgelist=curr->edgelist->enext;

                    }
                    else
                    {
                        
                        prev->enext=ecurr->enext;
                    }
                    free(ecurr);
                    return;
                }

                prev=ecurr;
                ecurr=ecurr->enext;
            }

        }
        
        curr=curr->vnext;
    }
    

}





void degree( int value)
{
    int count=0;
    vertex* curr=graph;
    if (value==curr->data)
    {
        edge*ecurr=curr->edgelist;
        while(ecurr!=NULL)
        {
            count++;
            ecurr=ecurr->enext;
        }

        cout<<count;

    }
}


void BFS() 
{

    // for if the function is called again it resets the visited to false 
    vertex* reset = graph;
    while (reset != NULL)
     {
        reset->visited = false;
        reset = reset->vnext;
    }


    vertex* curr = graph;
    vertex*output;



    Enqueue(curr);
    curr->visited=true;

    while(front!=NULL)
    {
        output=Dequeue();
        cout<<output->data<<" ";

        edge* ecurr=curr->edgelist;

        while(ecurr!=NULL)
        {


            if (ecurr->v->visited!=true)
            {
                ecurr->v->visited=true;
                Enqueue(ecurr->v);

            }
            ecurr=ecurr->enext;

        }
        curr=curr->vnext;
   
    }


}    





void DFS()
{
    vertex* reset = graph;
    while (reset != NULL)
     {
        reset->visited = false;
        reset = reset->vnext;
    }

    vertex* curr = graph;

    vertex*output;

    push(curr);

    while(top!=NULL)
    {
        output=pop();

        if (output->visited!=true)
        {
            cout<<output->data<<" ";
            output->visited=true;
        }


        edge*ecurr=output->edgelist;

        while(ecurr!=NULL)
        {
            if (ecurr->v->visited!=true)
            {
                push(ecurr->v);
            }


            ecurr=ecurr->enext;
        }

    }
}




int TotalVertices()
{
    int count=1;
    vertex*curr=graph;

    while (curr->vnext!=NULL)
    {
        curr=curr->vnext;
        count++;
    }
    return count;
    

}

edge* PushStack(edge*ecurr)

{
    if (ecurr->enext==NULL )
    {
        return NULL;
        
    }
    
    ecurr=ecurr->enext;
    PushStack(ecurr);
    
    if (ecurr->v->visited!=true)
    {
        push(ecurr->v);

    }

return NULL;
  
}



vertex*ArrList[100];

void PathArrDecl( )
{
    for (size_t i = 0; i < 100; i++)
    {
        ArrList[i]=NULL;
    }
    
}



vertex* FindPathDFS(char vert1,char vert2)
{  
    
    bool check= false;

    vertex* reset = graph;
    while (reset != NULL)
    {
        reset->visited = false;
        reset->parent=NULL;
        reset = reset->vnext;
    }
    
    
    vertex*curr = graph;
    while(curr!=NULL)
    {
        if (vert1==curr->data)
        {
            break;
        }
        curr=curr->vnext;
    }

    push(curr);
    curr->visited=true;

    vertex* found=NULL;

    while(top!=NULL)
    {
        
        vertex*output=pop();  
    
        if (output->data==vert2 )
        {
            found=output;
            break;
        }



        edge*ecurr=output->edgelist;

        while(ecurr!=NULL)
        {
            if (ecurr->v->visited!=true)
            {
                ecurr->v->visited=true;
                ecurr->v->parent=output;
                push(ecurr->v);
            }
            ecurr=ecurr->enext;
        }
    }


    if (found!=NULL)
    {
        top=NULL;

        vertex* start=found;

        while (start!=NULL)
        {
            push(start);
            start=start->parent;
            
        }


        while (top!=NULL)
        {
            cout<<pop()->data<<endl;
        }
        

        // for (size_t i = 0; i < 100; i++)
        // {
        //    if (ArrList[i]!=NULL)
        //    {
        //         cout<<ArrList[i]->data;
        //    }
            
        // }
        
    }

    else
    {
        cout<<"The vertex is nowhere to be found!"<<endl;
    }

    return 0;
}




vertex* FindPathBFS(char vert1 , char vert2)
{
    bool check=false;

    vertex* reset = graph;

    while (reset != NULL)
     {
        reset->visited = false;
        reset->parent=NULL;
        reset = reset->vnext;
    }




    vertex* curr = graph;
    while (curr!=NULL)
    {
        if (curr->data==vert1)
        {
            break;
        }
        curr=curr->vnext;
    }


    
    Enqueue(curr);
    curr->visited=true;
    
    vertex*found=NULL;
    while(front!=NULL)
    {
        vertex*output=Dequeue();
        // cout<<output->data<<" ";

        if (output->data==vert2 && check ==true)
        {
            found =output;
            break;
        }

        edge* ecurr=output->edgelist;

        check=true;
        while(ecurr!=NULL)
        {
            if (ecurr->v->visited!=true)
            {
                ecurr->v->visited=true;
                ecurr->v->parent=output;
                Enqueue(ecurr->v);
            }
            ecurr=ecurr->enext;
        }
    
    }

    if (found!=NULL)
    {
        vertex*traverse=found;

        while (traverse!=NULL)
        {
            push(traverse);
            traverse=traverse->parent;
        }

        while (top!=NULL)
        {
            cout<<pop()->data<<endl;
        }
                
    }
    else
    {
        cout<<"The vertex is nowhere to be found!"<<endl;
    }
return NULL;
}






void display()
{
    vertex*curr=graph;
    edge*ecurr;
    if (graph!=NULL)
    {
        while(curr!=NULL)
        {
            
            cout<<curr->data<<" | ";
            ecurr=curr->edgelist;
            while(ecurr!=NULL)
            {
                cout<<ecurr->v->data<<" ";
                ecurr=ecurr->enext;

            }
            curr=curr->vnext;


            cout<<endl;
        }
    }
    else
    {
        cout<<"Graph is empty"<<endl;
    }
}



void MatrixForm()
{
    int n=5;
    int arraymat[n][n];

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            arraymat[i][j]=0;
        }
        
    }
    

    vertex* curr=graph;


    
    int i=0;
    int j=0;
    while(curr!=NULL)
    {
        edge* ecurr=curr->edgelist;
        
        while (ecurr!=NULL)
        {
            if (ecurr->v->data==curr->data)
            {
                arraymat[i][j]=1;
            }
            j++;
            curr=curr->vnext;
        }
        
        ecurr=ecurr->enext;

    }

}




int main ()
{
    int choice; 
    char val, num1, num2,val1,val2;
    int count=0;
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add vertex \n2. Display \n3. Add Edge \n4. Remove vertex \n5. Matrix form \n6. degree \n7. BFS\n8. Remove Edge \n9. DFS\n10. Find Path DFS\n11. Find Path BFS\n12. Exit\n";
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) // If input is NOT an integer
        {
            cout << "Please enter a valid number!" << endl;
            cin.clear(); // Clear the error flags
            cin.ignore(1000, '\n'); // Discard the bad input buffer
            continue; // Start the loop over
        }
        
        switch(choice) 
        {
            case 1:
                cout << "Enter the vertex to add: ";
                cin >> val;
            
                AddVertex(val);
            
                count++;

                cout<<"Total Verices: "<<count<<endl;

                break;
            case 2:
                display();

                break;

            case 3:
                cout << "Enter vertex 1: ";
                cin >> num1;
            
                cout << "Enter vertex 2 to attach: ";
                cin >> num2;

                AddEdge(num1,num2);

                break;

            case 4:
                cout << "Enter the vertex to remove: ";
                cin >> val;
            
                RemoveVertex(val);

                break;

            case 5:
                MatrixForm();

                break;
                    
            case 6:
                cout << "Enter the vertex for degree: ";
                cin >> val;
            
                degree(val);

                break;
                
            case 7:
                BFS();

                break;
                
            case 8:
                cout << "Enter the vertex to remove from: ";
                cin >> val1;
            
                cout << "Enter the vertex to be removed: ";
                cin >> val2;
            
                RemoveEdge(val1,val2);

                break;

            case 9:
                DFS();

                break;


            case 10:
                cout << "Enter the vertex 1: ";
                cin >> val1;

                cout << "Enter the vertex 2: ";
                cin >> val2;

                PathArrDecl();
                FindPathDFS(val1,val2);
            
                break;

            case 11:
                cout << "Enter the vertex 1: ";
                cin >> val1;

                cout << "Enter the vertex 2: ";
                cin >> val2;

                PathArrDecl();
                FindPathBFS(val1,val2);

                break;  

            case 12:

                return 0; // Proper way to exit

            default:
            
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}


