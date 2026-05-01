#include<iostream>
#include<stdlib.h>
using namespace std;

struct SNode // for the student Clist node 
{
    int SNo; // like the data variable as in the rest of the linked Clist
    SNode * Snext;  // separated the student and course nexts
    SNode * stu_list; 

};

struct CNode // for the course Clist node 
{
    int CNo;
    CNode * Cnext;  
    SNode * stu_list;

};

CNode*Clist=NULL;  // course Clist is NULL

// the overall structure of the nested lists are 

//  Clist
//    |             |           |
//  course 1    course 2    course 3    ...
//    |             |           |
//  student 1   student 1   student 1
//  student 2   student 2   student 2
//  student 3   student 3   student 3
//  ....
// 

void insert_course(int value)
{
    CNode*temp;  // temp for the courses
    temp=(CNode*)malloc(sizeof(CNode));
    temp->CNo=value; 
    temp->Cnext=NULL;  // the course lists's Cnext is null accessing through temp
    
    temp->stu_list=NULL; // and acessing the stud. Clist through tmep and making it null because 

    if (Clist==NULL)
    {
        Clist=temp; // here the temp had the vlaue and Cnext NULL and also the stu Clist so it all trnasfered to the clist
    }
    else
    {
        CNode*Ccurr=Clist; // same as that of the sigle linked Clist 
        while(Ccurr->Cnext!=NULL) 
        {
            Ccurr=Ccurr->Cnext; 
        }
        Ccurr->Cnext=temp;
    }


}



void display_course()
{
    CNode*Ccurr=Clist;
    if (Clist!=NULL)
    {
        while(Ccurr!=NULL)
        {
            
            cout<<Ccurr->CNo<<" ";
            Ccurr=Ccurr->Cnext;
        }
        cout<<endl;
    }
    else
    {
        cout<<"List is empty"<<endl;
    }
}



void insert_stu(int val1, int val2) // takes two inputs one to check for the course no. and other for the student roll no.
{
    CNode* Ccurr=Clist;
    while (Ccurr != NULL)
    {

        if (val1==Ccurr->CNo)
        {
            SNode*temp;
            temp=(SNode*)malloc(sizeof(SNode));
            temp->SNo=val2;
            temp->Snext=NULL;

            if (Ccurr->stu_list==NULL) // normally we check if the Clist is null but now the Clist is linked with the courses so the Ccurr tells the current course we are on and then in the Ccurr course's student Clist we check if it is empty or not
            {
                Ccurr->stu_list=temp;  // temp assigned to the currrent course's student's Clist 
                return;

            }
            else
            {
                SNode*Scurr=Ccurr->stu_list; // else come up with the new scurr for the student which points to the stu Clist
                                             // basically wherever we are accessing the nested lists we have to approach it with the Ccurr 

                while(Scurr->Snext!=NULL) // iterate the scurr to the end for the linking the chain to the end node
                {
                    Scurr=Scurr->Snext; 
                }
                Scurr->Snext=temp; 
            }
            return;

        }
        Ccurr=Ccurr->Cnext; // for the Cnext of the ccurr if the course not matches in the first if condition 
    }

    return; // course not found
}






// void Delete_student(int seat)
// {
//     CNode* Ccurr = Clist;
    
//     if (Ccurr == NULL)
//     {
//         cout << "Course List is empty, deletion not possible" << endl;
//         return;
//     }
    
//     while (Ccurr != NULL)
//     {
//         SNode* Scurr = Ccurr->stu_list;
//         SNode* prev = NULL;

//         // Corrected logic: Use a standard linked list deletion pattern
//         while (Scurr != NULL)
//         {
//             if (Scurr->SNo == seat)
//             {
//                 if (prev == NULL) // Case: Student is at the head of the list
//                 {
//                     Ccurr->stu_list = Scurr->Snext;
//                 }
//                 else // Case: Student is in the middle or end
//                 {
//                     prev->Snext = Scurr->Snext;
//                 }
                
//                 free(Scurr);
//                 cout << "Student deleted: " << seat << endl;
//                 // return; // Exit function once deleted
//                 continue;
//             }
            
//             prev = Scurr;
//             Scurr = Scurr->Snext;
//         }
        
//         // Fix: Move course increment OUTSIDE the student while loop
//         Ccurr = Ccurr->Cnext;
//     }
     
//     cout << "Student " << seat << " not found in any course." << endl;
// }










void Delete_course(int value)
{
    CNode*Ccurr=Clist;
    CNode*prev=NULL;
    


    if(Ccurr==NULL)
    {
        cout<<"Course List is empty, deletion not possible"<<endl;
        return;
    }
    

    
    while(Ccurr!=NULL) // this for the loop to run until the Ccurr is not null for the course traversing
    {
        
        
        if (value==Ccurr->CNo) // first case if the value matches the first course in the list
        {
            Clist=Clist->Cnext; // joins the course list to the second elemnt
            SNode* Scurr = Ccurr->stu_list; // scurr points to the stu_list
           
            while(Scurr!=NULL) // iterates until the scurr is not null
            {
                Ccurr->stu_list=Ccurr->stu_list->Snext;  //joins the stu list to the list's second elemnt

                free(Scurr); // frees the scurr which is in first run is at first elemnt

                Scurr= Ccurr->stu_list; // points the scurr again at the list's first elemnt so that the elemnt deletion is always from the first element
                // Scurr=Scurr->Snext;
            }
            free(Ccurr); // when the scurr is null and all the students gets deleted the Ccurr is now freed
            return; // returned from here so that now the Ccurr is not moved to the next
        }           

        prev=Clist;
        Ccurr=Ccurr->Cnext;

        while (Ccurr !=NULL)
        {
            if (value==Ccurr->CNo)
            {
                prev->Cnext=Ccurr->Cnext;
                SNode* Scurr = Ccurr->stu_list;

                while(Scurr!=NULL) // iterates until the scurr is not null
                {
                    Ccurr->stu_list=Ccurr->stu_list->Snext;  //joins the stu list to the list's second elemnt

                    free(Scurr); // frees the scurr which is in first run is at first elemnt

                    Scurr= Ccurr->stu_list; // points the scurr again at the list's first elemnt so that the elemnt deletion is always from the first element
                    // Scurr=Scurr->Snext;
                }
                free(Ccurr); // when the scurr is null and all the students gets deleted the Ccurr is now freed
                return;
            }
            prev=Ccurr;
            Ccurr=Ccurr->Cnext;
        }
    }
            

}









void display_all()
{
    CNode*Ccurr=Clist;
    if (Clist!=NULL)
    {
        while(Ccurr!=NULL) // while loop for the course lists
        {
            
            cout<<"\nThe course number "<<Ccurr->CNo<<endl;
            
            SNode*Scurr=Ccurr->stu_list;
            cout<<"The roll number of students enrolled in this course are:\n";

            // if (Scurr==NULL) // if the students list is empty 
            // {
            //     cout<<"There are no Students enrolled in this course currently\n";
            //     return;
            // }
            // else
            // {
                while(Scurr!=NULL) // another while loop for the student list
                {
                    cout<<Scurr->SNo<<"\n";
                    Scurr=Scurr->Snext;
                }
                
                Ccurr=Ccurr->Cnext;
            // }

            
        }
        cout<<endl;
    }
    else
    {
        cout<<"List is empty"<<endl;
    }
}




int main()
{
    int choice, val,num,val1,val2;
    string stateC,stateS; 
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert course \n2. Insert student \n3. Display All \n4. Display Courses \n5. Delete a Course \n";
        cout << "Enter choice: ";
        cin >> choice; 
        
        switch(choice) 
        {
            case 1:
                
                while(true)
                    {
                        cout << "Enter value to insert: ";
                        cin >> val;
                        insert_course(val);

                        cout<<"Do you want to add more courses? y/n"<<endl;
                        cin>>stateC;
                        if (stateC!="y")
                        {
                            break;
                        }
                    
                    }
                    break;
            
            case 2:

                while(true)
                {
                    int val1,val2;
                    cout<<"Enter the course number you want the student to enroll: ";
                    cin>>val1;
                    cout<<"Enter the seat number of the student: ";
                    cin>>val2;
                    insert_stu(val1,val2);

                    cout<<"Do you want to add more students? y/n"<<endl;
                    cin>>stateS;
                    if (stateS!="y")
                    {
                        break;
                    }
                }
                break;
                

            case 3:

                display_all();
                break;

            case 4:

                display_course();
                break;
                
            case 5:

                cout << "Enter the course to be deleted: ";
                cin >> val1;
                Delete_course(val1);
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