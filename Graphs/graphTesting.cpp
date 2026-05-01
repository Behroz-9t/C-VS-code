#include <iostream>
#include <stdlib.h>
using namespace std;
struct Vertex;

struct Edge;

struct dqueue{
    Vertex* data;
    dqueue*next;
 };
dqueue*qrare=NULL;
dqueue*qfront=NULL;

void Enqueue(Vertex*value){
    if (value==NULL)
    {
        return;
    }
    
    dqueue*temp=(dqueue*)malloc(sizeof(dqueue));
    temp->data=value;
    temp->next=NULL;
    if (qrare==NULL && qfront==NULL)
    {
        qrare=temp;
        qfront=qrare;
        
    }else 
    {
        qrare->next=temp;
        qrare=qrare->next;
       
    }
}


Vertex * Dequeue(){
    if (qfront==NULL)
    {
        return NULL;
    }
    dqueue*temp=qfront;
    Vertex*value=temp->data;
    
    
    // if only one node.
      if (qrare==qfront)
      {
        free(qfront);
        qrare=NULL;
        qfront=NULL;
        
      }else
      {
        qfront=qfront->next;
      }  
    free(temp);
    return value;
}





struct Vertex
{
    char data;
    Vertex *vnext;
    Edge *Edgelist;
    bool visited;
};
struct Edge
{
    Edge *enext;
    Vertex *v;
};
Vertex *graph = NULL;

void addVertex(char value)
{
    Vertex *temp = (Vertex *)malloc(sizeof(Vertex));
    temp->data = value;
    temp->vnext = NULL;
    temp->Edgelist = NULL;
    temp->visited=false;
    if (graph == NULL)
    {
        graph = temp;
        return;
    }
    Vertex *curr = graph;
    while (curr->vnext != NULL)
    {
        curr = curr->vnext;
    }
    curr->vnext = temp;
}
Vertex *address(char a)
{
    Vertex *curr = graph;
    Vertex *address;
    while (curr != NULL)
    {
        if (a == curr->data)
        {
            return curr;
        }
        curr = curr->vnext;
    }
    cout << "The vertex does not exist." << endl;
    return NULL;
}
void addEdge(char vertex1, char vertex2)
{
    Vertex *v1 = address(vertex1);
    Vertex *v2 = address(vertex2);
    if (v1 == NULL || v2 == NULL)
    {
        cout << "Vertex does not Exist." << endl;
        return;
    }
    // V1 - v2 to edge
    Edge *temp1 = (Edge *)malloc(sizeof(Edge));
    temp1->v = v2;
    temp1->enext = NULL;
    if (v1->Edgelist == NULL)
    {
        v1->Edgelist = temp1;
    }
    else
    {
        Edge *curr1 = v1->Edgelist;
        while (curr1->enext != NULL)
        {
            curr1 = curr1->enext;
        }
        curr1->enext = temp1;
    }
    // v2 to v1 edge
    Edge *temp2 = (Edge *)malloc(sizeof(Edge));
    temp2->v = v1;
    temp2->enext = NULL;
    if (v2->Edgelist == NULL)
    {
        v2->Edgelist = temp2;
    }
    else
    {
        Edge *curr2 = v2->Edgelist;
        while (curr2->enext != NULL)
        {
            curr2 = curr2->enext;
        }
        curr2->enext = temp2;
    }
}
void display()
{
    Vertex *curr = graph;
    Edge *ecurr;
    if (graph != NULL)
    {
        while (curr != NULL)
        {

            cout << curr->data << " | ";
            ecurr = curr->Edgelist;
            while (ecurr != NULL)
            {
                cout << ecurr->v->data << " ";
                ecurr = ecurr->enext;
            }
            curr = curr->vnext;

            cout << endl;
        }
    }
    else
    {
        cout << "Graph is empty" << endl;
    }
}
void Degree()
{
    Vertex *v = graph;
    while (v != NULL)
    {
        Edge *e = v->Edgelist;
        int count = 0;
        while (e != NULL)
        {
            count++;
            //

            e = e->enext;
        }
        cout << "Degree of Vertix : " << count << endl;
        v = v->vnext;
    }
}
void BFS()
{
    if(graph==NULL)
    {
        return;
    }
    Vertex*t=graph;
    while (t!=NULL)
    {
        t->visited=false;
        t=t->vnext;
    }
    Vertex*ver=graph;
    
   
    Enqueue(ver);
    ver->visited=true;

    

    while (qfront!=NULL)
    {
       Vertex * output=Dequeue();
       
       if (output==NULL)
       {
           continue;
        }
        cout<<output->data << " ";
          
        Edge*e=output->Edgelist;

        while (e!=NULL)
        {
            if (e->v->visited!=true)
            {
                e->v->visited=true;
                Enqueue(e->v);
            }
            e=e->enext;
        }
        
    }
}
int main()
{
    int choice;
    char val, num1, num2;

    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Vertex \n2. Display \n3. Add Edge \n4. Adjacency Matrix \n5. Degree \n6. BFS \n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            addVertex(val);
            break;

        case 2:
            display();
            break;

        case 3:
            cout << "Enter vertex I:";
            cin >> num1;
            cout << "Enter vertex II to attach:";
            cin >> num2;
            addEdge(num1, num2);
            break;

            // case 4:
            //     MatrixPrint();
            //     break;

        case 5:
            Degree();
            break;
        case 6:
            BFS();
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}