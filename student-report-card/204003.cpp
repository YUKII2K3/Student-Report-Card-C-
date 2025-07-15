// Student Report Card (C++) by Yuktheshwar
// Original project by Jahed Hasan. Updated with permission.
// Repository: https://github.com/YUKII2K3/Student-Report-Card-C-.git
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

class student
{
protected:
    string name, roll_no;
};
class course_marks{
    protected:
        float marks[5];
};
class result:public student, public course_marks{
     float avg;
    char grade;
    void getAvg()
    {
       avg=(marks[0]+marks[1]+marks[2]+marks[3]+marks[4])/5;
    }
    void getgrade()
      {
           if(avg>=80)
           grade='A';
           else if((avg>=60)&&(avg<=79))
           grade='B';
           else if((avg>=40)&&(avg<=59))
           grade='C';
           else if((avg>=35)&&(avg<=39))
           grade='D';
           else if(avg<35)
           grade='E';
      }
    public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    void generate_report();
};
// Project Menu
void result::menu()
{
    menustart:
        int choice;
        char x;
        system("cls");
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| STUDENT REPORT CARD (C++) by Yuktheshwar |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t 2. Display All Record" << endl;
        cout << "\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t 6. Generate Report Card" << endl;
        cout << "\t\t\t 7. Exit\n"
             << endl;

        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7]" << endl;
        cout << "\t\t\t............................" << endl;
        cout << " Enter Your Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            generate_report();
            break;
        case 7:
            cout << "\n\t\t\t Program Is Exit";
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
        }
        getch();
        goto menustart;
}
void result::insert() // Add student details
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Enter The Course Marks ---------------------------------------------" << endl;
    cout<<"\t\t\tPHYSICS    : ";
    cin>>marks[0];
    cout<<"\t\t\tCHEMISTRY  : ";
    cin>>marks[1];
    cout<<"\t\t\tMATHEMATICS: ";
    cin>>marks[2];
    cout<<"\t\t\tPROGRAMMING: ";
    cin>>marks[3];
    cout<<"\t\t\tENGLISH    : ";
    cin>>marks[4];


    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " "  << marks[0] << " "  << marks[1] << " "  << marks[2] << " "  << marks[3] << " "  << marks[4] << " " << "\n";
    file.close();
}
void result::display() // Display data of student
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] ;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tRoll No.: " << roll_no << "\n";
            cout << "\t\t\tPHYSICS: "<< marks[0] << "\n";
            cout << "\t\t\tCHEMISTRY: "<< marks[1] << "\n";
            cout << "\t\t\tMATHEMATICS: "<< marks[2] << "\n";
            cout << "\t\t\tPROGRAMMING: "<< marks[3] << "\n";
            cout << "\t\t\tENGLISH: "<< marks[4] << "\n";


            file >> name >> roll_no >> marks[0] >> marks[1] >> marks [2] >> marks[3] >> marks[4];
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void result::modify() // Modify details of student
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
        while (!file.eof())
        {
            if (rollno != roll_no)
                file1 << " " << name << " " << roll_no << " " << marks[0] << " " << marks[1] << " " << marks[2] << marks[3] << " " << marks[4] << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "------- Enter Marks ------" << endl;
                cout<<"\t\t\tPHYSICS    : ";
                cin>>marks[0];
                cout<<"\t\t\tCHEMISTRY  : ";
                cin>>marks[1];
                cout<<"\t\t\tMATHEMATICS: ";
                cin>>marks[2];
                cout<<"\t\t\tPROGRAMMING: ";
                cin>>marks[3];
                cout<<"\t\t\tENGLISH    : ";
                cin>>marks[4];

                file1 << " " << name << " " << roll_no << " "  << marks[0] << " "  << marks[1] << " "  << marks[2] << " "  << marks[3] << " "  << marks[4] << " " << "\n";
                found++;
            }
            file >> name >> roll_no >> marks[0] >> marks[1] >> marks [2] >> marks[3] >> marks[4];
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void result::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tPHYSICS: "<< marks[0] << "\n";
                cout << "\t\t\tCHEMISTRY: "<< marks[1] << "\n";
                cout << "\t\t\tMATHEMATICS: "<< marks[2] << "\n";
                cout << "\t\t\tPROGRAMMING: "<< marks[3] << "\n";
                cout << "\t\t\tENGLISH: "<< marks[4] << "\n";
                found++;
            }
            file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4]; ;
            if (found == 0)
            {
                cout << "\n\t\t\t Student Roll NO. Not Found....";
            }
        }
        file.close();
    }
}
void result::deleted() // ddeleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];

        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " "  << marks[0] << " "  << marks[1] << " "  << marks[2] << " "  << marks[3] << " "  << marks[4] << " " << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
void result::generate_report() // generate report card for specific student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to generate report card: ";
        cin >> rollno;
        system("cls");
        file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
        while (!file.eof())
        {
            if (rollno == roll_no)
            {   this->getAvg();
                this->getgrade();
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout<<"                        DHAKA UNIVERSITY OF ENGINEERING & TECHNOLOGY (DUET), GAZIPUR\n\n";
                cout<<"                                        STUDENT REPORT CARD (C++) by Yuktheshwar";
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout<<"                                     ------------------------\n";
                cout<<"                                         PERSONAL DETAILS\n";
                cout<<"                                     ------------------------\n\n";
                cout<<"\t\t\t NAME: "<<name<<"\t";
                cout<<"\t\tROLL NO: "<<roll_no<<"\n\n";
                cout<<"\t\tTELEPHONE: 0123-45678\t";
                cout<<"DEPT.: Computer Science and Engineering (CSE)\n\n";
                cout<<"                        ----------------------------\n";
                cout<<"                            ACADEMIC PERFORMANCE\n";
                cout<<"                        ----------------------------\n\n";
                cout<<"                 ---------------------------------------\n";
                cout<<"                                  MARKS\n";
                cout<<"                 ---------------------------------------\n";

                cout<<"\t\t\t  PHYSICS\t"<<marks[0]<<"\n";
                cout<<"\t\t\t  CHEMISTRY\t"<<marks[1]<<"\n";
                cout<<"\t\t\t  MATHEMATICS\t"<<marks[2]<<"\n";
                cout<<"\t\t\t  PROGRAMMING\t"<<marks[3]<<"\n";
                cout<<"\t\t\t  ENGLISH\t"<<marks[4]<<"\n";

                cout<<"                -------------------        ------------\n";
                cout<<"                 PERCENTAGE: "<<avg<<"%"<<"           ";
                cout<<"GRADE: "<<grade<<"\n";
                cout<<"                -------------------        ------------\n\n";

                found++;
            }
            file >> name >> roll_no >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4]; ;
            if (found == 0)
            {
                cout << "\n\t\t\t Student Roll NO. Not Found....";
            }
        }
        file.close();
    }
}

main()
{
   result r;
   r.menu();
}

