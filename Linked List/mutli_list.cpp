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

void search_course(int value)
{
    CNode*Ccurr=Clist;
    while(Ccurr!=NULL)
    {
        if(Ccurr->CNo==value)
        {
            cout<<"Value found: "<<value<<endl;
            return;
        }
        Ccurr=Ccurr->Cnext;
    }
    cout<<"Value not found: "<<value<<endl;
 
    
}


void search_stu_in_course(int course,int seat)
{
    CNode*Ccurr=Clist;
    bool found=false;

    if(Ccurr==NULL)
    {
        cout<<"Course List is empty, Search is not possible"<<endl;
        return;
    }
    
    while(Ccurr!=NULL) // this for the loop to run until the Ccurr is not null for the course traversing
    {
        
        
        if(course==Ccurr->CNo) // if course matches then only check student
        {
            
            SNode*Scurr=Ccurr->stu_list; // scurr is standing at the list's first elemt
            // SNode*prev=NULL;

            if (Scurr==NULL)
            { 
                cout<<"Student list is empty in the course, search not possible";
                return;
            }

            if (seat==Scurr->SNo) // first case sceario when we want to delete the first elemnt of the list
            {
               cout<< "Student found of seat number: "<<seat<<" in course number: "<<course<<endl;
               found=true;
               return;
            }
        
            
            Scurr=Scurr->Snext; // moves forward the scurr to the second elemnt
            
            // prev=Ccurr->stu_list; // prev points to the stu_list
           
            while (Scurr!=NULL) // now we want to traverse all the students except first elemnt
            {
                if(Scurr->SNo==seat) // matches the seat 
                {
                    // prev->Snext=Scurr->Snext;  // joins the prev elemnt's next to the curr element's next
                    
                    cout<< "Student found of seat number: "<<seat<<" in course number: "<<course<<endl;
                    found=true;
                    return;
                }
                // prev=Scurr;
                Scurr=Scurr->Snext;
            }   

            if (found!=true)
            {
                cout<<"Student not found of seat number: "<<seat<<endl;
            }
        }
        Ccurr=Ccurr->Cnext;
    }
 
    
}




void search_student(int seat)
{
    CNode*Ccurr=Clist;
    bool found=false;
    int count=0;

    if(Ccurr==NULL)
    {
        cout<<"Course List is empty, Search is not possible"<<endl;
        return;
    }
    
    while(Ccurr!=NULL) // this for the loop to run until the Ccurr is not null for the course traversing
    {
        SNode*Scurr=Ccurr->stu_list;

        while(Scurr!=NULL)
        {
        
            // if(seat==Scurr->SNo) // if course matches then only check student
            // {
                
                // SNode*Scurr=Ccurr->stu_list; // scurr is standing at the list's first elemt
                // SNode*prev=NULL;

                if (Scurr==NULL)
                { 
                    cout<<"Student list is empty in the course, search not possible";
                    return;
                }
                
                while(Scurr!=NULL){

                    if (seat==Scurr->SNo) // first case sceario when we want to delete the first elemnt of the list
                    {
                        found=true;
                        count++;
                        
                        
                    }
                    Scurr=Scurr->Snext;
                }
                // }
                // Scurr=Scurr->Snext;
            }
            Ccurr=Ccurr->Cnext;
        }
        
    if (found!=true)
        {
            cout<<"Student not found of seat number: "<<seat<<endl;
        }
    cout<< "Student found of seat number "<<seat<<" in "<<count<<" courses."<< endl;
    return;
 
    
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




void Delete_student_from_a_course(int course,int seat)
{
    CNode*Ccurr=Clist;
    //


    if(Ccurr==NULL)
    {
        cout<<"Course List is empty, deletion not possible"<<endl;
        return;
    }
    
    while(Ccurr!=NULL) // this for the loop to run until the Ccurr is not null for the course traversing
    {
        
        
        if(course==Ccurr->CNo) // if course matches then only check student
        {
            
            SNode*Scurr=Ccurr->stu_list; // scurr is standing at the list's first elemt
            SNode*prev=NULL;

            if (Scurr==NULL)
            { 
                cout<<"Student list is empty in the course";
                return;
            }

            if (seat==Scurr->SNo) // first case sceario when we want to delete the first elemnt of the list
            {
                // Ccurr->stu_list=Scurr->Snext; // (joins the list to the list's second elemnt) same as that when we write: list = list -> next
                Ccurr->stu_list=Ccurr->stu_list->Snext; // alternate to the above line

                free(Scurr); // frees the scurr which is pointing to the first elemnt
                cout<<"Student deleted: "<<seat;
                return;
            }
        
            
            Scurr=Scurr->Snext; // moves forward the scurr to the second elemnt
            
            prev=Ccurr->stu_list; // prev points to the stu_list
           
            while (Scurr!=NULL) // now we want to traverse all the students except first elemnt
            {
                if(Scurr->SNo==seat) // matches the seat 
                {
                    prev->Snext=Scurr->Snext;  // joins the prev elemnt's next to the curr element's next
                    
                    free(Scurr);
                    cout<<"Student deleted of seat number: "<<seat<<endl;
                    return;
                }
                prev=Scurr;
                Scurr=Scurr->Snext;
            }   
            cout<<"Student not found: "<<seat<<endl;
        }
        Ccurr=Ccurr->Cnext;
    }
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


void Delete_student2(int seat)
{
    CNode*Ccurr=Clist;
    //


    if(Ccurr==NULL)
    {
        cout<<"Course List is empty, deletion not possible"<<endl;
        return;
    }
    
    while(Ccurr!=NULL) // this for the loop to run until the Ccurr is not null for the course traversing
    {
        
        
        
            
            SNode*Scurr=Ccurr->stu_list; // scurr is standing at the list's first elemt
            SNode*prev=NULL;

            if (Scurr==NULL) // if the stu list is empty 
            { 
                cout<<"Student list is empty in the course";
                return;
            }


            int count = 0;
            
            // if (seat==Scurr->SNo) // first case sceario when we want to delete the first elemnt of the list
            // {
               
                while(Ccurr!=NULL & seat==Scurr->SNo) // loop until the Course curr is not null
                {


                    count++; // for the number of times the loop executed
                    Ccurr->stu_list=Ccurr->stu_list->Snext; // joins the stu list to the second element
                    
                    free(Scurr); // frees the scurr which is pointing to the first elemnt

                    Ccurr=Ccurr->Cnext; // updates the course curr to the next course
                    if (Ccurr!=  NULL) // to make sure when the Ccurr is null the scurr doesnot go further
                    {
                        Scurr=Ccurr->stu_list; // makes the scurr to point to the updated course curr's stu list
                    }
                    else{
                        cout<<"Student deleted of seat number: "<<seat<<" from all the available "<<count<<" courses!";
                        return;
                    }
                    
                }
                
            // }
            
        
            
            Scurr=Scurr->Snext; // moves forward the scurr to the second elemnt
            
            prev=Ccurr->stu_list; // prev points to the stu_list
           
            // while (Scurr!=NULL) // now we want to traverse all the students except first elemnt
            // {
            //     if(Scurr->SNo==seat) // matches the seat 
            //     {
            //         prev->Snext=Scurr->Snext;  // joins the prev elemnt's next to the curr element's next
                    
            //         free(Scurr);
            //         cout<<"Student deleted of seat number: "<<seat<<endl;
            //         return;
            //     }
            //     prev=Scurr;
            //     Scurr=Scurr->Snext;
            // }   
            // cout<<"Student not found: "<<seat<<endl;
        
        Ccurr=Ccurr->Cnext;
    }
}






void Delete_student(int seat)
{
    CNode* Ccurr = Clist;
   

    if (Ccurr == NULL)
    {
        cout << "Course List is empty, deletion not possible" << endl;
        return;
    }

    while (Ccurr != NULL)
    {
        SNode* Scurr = Ccurr->stu_list;
        SNode* prev = NULL;

        while (Scurr != NULL)
        {
            if (Scurr->SNo == seat)
            {
                SNode* temp = Scurr; // Store node to free it later
                
                if (prev == NULL) // Case: Student is at the head
                {
                    Ccurr->stu_list = Scurr->Snext;
                    Scurr = Ccurr->stu_list; // Move Scurr to the new head
                }
                else // Case: Student is in the middle or end
                {
                    prev->Snext = Scurr->Snext;
                    Scurr = prev->Snext; // Move Scurr to the next valid node
                }

                free(temp);
                cout << "Student deleted from Course " << Ccurr->CNo << " : " << seat << endl;
               
                
                // Note: We don't 'return' here because we want to check other courses
                // and we don't 'break' because a student might (theoretically) be 
                // listed twice in one course depending on your logic.
                continue; 
            }

            prev = Scurr;
            Scurr = Scurr->Snext;
        }
        Ccurr = Ccurr->Cnext;
    }

 
}

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
    string state; 
    
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert course \n2. Insert student \n3. Search Course \n4. Search student  \n5. Search a student in a course  \n6. Delete a course \n7. Delete Student from a course \n8. Delete student \n9. Delete student 2nd Edition \n10. Display All \n11. Display Courses  \n12. Exit \n";
        cout << "Enter choice: ";
        cin >> choice; 
        
        switch(choice) 
        {
            case 1:
                
                while(true)
                    {
                        cout << "Enter the course: ";
                        cin >> val;
                        insert_course(val);

                        cout<<"Do you want to add more courses? y/n"<<endl;
                        cin>>state;
                        if (state!="y")
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
                    cin>>state;
                    if (state!="y")
                    {
                        break;
                    }
                }
                break;
                

            case 3:
                
                cout << "Enter value to search: ";
                cin >> num;
                search_course(num);
                break;


            case 4:

                while(true)
                {
                    cout << "Enter the seat number to search a student: ";
                    cin >> val1;

                    search_student(val1);
                    cout<<"Do you want to search more students? y/n"<<endl;
                    cin>>state;
                    if (state!="y")
                    {
                        break;
                    }
                }
                break;

            case 5:

                while(true)
                {
                    cout << "Enter the course from which you want to search a student: ";
                    cin >> val1;
                
                    cout << "Enter the seat number to search a student: ";
                    cin >> val2;

                    search_stu_in_course(val1,val2);
                    cout<<"Do you want to search more students? y/n"<<endl;
                    cin>>state;
                    if (state!="y")
                    {
                        break;
                    }
                }
                break;


            case 6:

                cout << "Enter the course to be deleted: ";
                cin >> val1;
                Delete_course(val1);
                break;


                cout << "Enter the course from which you want to delete a student: ";
                cin >> val1;
            
                cout << "Enter the seat number of the student to be deleted: ";
                cin >> val2;
                Delete_student_from_a_course(val1,val2);
                break;

            case 7:

                cout << "Enter the course from which you want to delete a student: ";
                cin >> val1;
            
                cout << "Enter the seat number of the student to be deleted: ";
                cin >> val2;
                Delete_student_from_a_course(val1,val2);
                break;




            case 8:


                cout << "Enter the seat number of the student to be deleted: ";
                cin >> val1;
                Delete_student(val1);
                break;

               
            case 9:

                cout << "Enter the seat number of the student to be deleted: ";
                cin >> val1;
                Delete_student2(val1);
                break;


                
            case 10:

                display_all();
                break;



            case 11:

                display_course();
                break;


            case 12:
                exit(0);
                break;


            

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;

}