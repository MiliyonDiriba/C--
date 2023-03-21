// Hotel Management system using file handling in c++
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <stdio.h>
using namespace std;
class hotel
{
private:
    string name, id, duration, address, room_no, phone_no;

public:
    void menu();
	void addAndSaveGuest();
    void display();
    void updateGuest();
    void searchGuest();
    void deleteGuest();
	void calculate();
};
void hotel::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| hotel Management SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Add Guest" << endl;
    cout << "\t\t\t 2. Display information" << endl;
    cout << "\t\t\t 3. update Guest" << endl;
    cout << "\t\t\t 4. search Guest" << endl;
    cout << "\t\t\t 5. Delete Guest" << endl;
	cout << "\t\t\t 6. Calculate Price" << endl;
    cout << "\t\t\t 7. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

        // Call the appropriate function based on the user's choice
    switch (choice)
    {
    case 1:
        do
        {
            addAndSaveGuest();
            cout << "\n\t\t\t Add Another hotel Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        updateGuest();
        break;
    case 4:
        searchGuest();
        break;
    case 5:
        deleteGuest();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void hotel::addAndSaveGuest() 
    // Create a new guest object
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Guest Details ---------------------------------------------" << endl;
    
    cout << "\t\t\tEnter Guest Name: ";
    cin >>name;
    cout << "\t\t\tEnter Guest Id.: ";
    cin >> id;
    cout << "\t\t\tEnter duration of stay (in days): ";
    cin >> duration;
    cout << "\t\t\tEnter Guest Room Number: ";
    cin >> room_no;
    cout << "\t\t\tEnter Guest Phone No: ";
    cin >> phone_no;
    cout << "\t\t\tEnter Guest Address: ";
    cin >> address;
    file.open("guestRecord.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << duration << " " << room_no << " " << phone_no << " " << address << "\n";
    file.close();
}

void hotel::display() // display Guest details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Guest Record Table --------------------------------------------" << endl;
    file.open("guestRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> id >> duration >> room_no >> phone_no >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t  No.: " << total++ << endl;
            cout << "\t\t\t Guest Name: " << name << endl;
            cout << "\t\t\t Guest id.: " << id << endl;
            cout << "\t\t\t duration of stay: " << duration << endl;
            cout << "\t\t\t Room Number: " << room_no << endl;
            cout << "\t\t\t Phone No.: " << phone_no << endl;
            cout << "\t\t\t Guest Address: " << address << endl;
            file >> name >> id >> duration >> room_no >> phone_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}
void hotel::updateGuest() // update Guest Details
{
    system("cls");
    fstream file, file1;
    string guest_id;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- hotel updateGuest Details ------------------------------------------" << endl;
    file.open("guestRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter id No. of guest that you want to update: ";
        cin >> guest_id;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> duration >> room_no >> phone_no >> address;
        while (!file.eof())
        {
            if (guest_id != id)

                file1 << " " << name << " " << id << " " << duration << " " << room_no << " " << phone_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Guest Name: ";
                cin >> name;
                cout << "\t\t\tEnter Guest Id.: ";
                cin >> id;
                cout << "\t\t\tEnter duration of stay (in days): ";
                cin >> duration;
                cout << "\t\t\tEnter Guest Room Number: ";
                cin >> room_no;
                cout << "\t\t\tEnter Guest Phone No: ";
                cin >> phone_no;
                cout << "\t\t\tEnter Guest Address ";
                cin >> address;
                file1 << " " << name << " " << id << " " << duration << " " << room_no << " " << phone_no << " " << address << "\n";
                found++;
            }
            file >> name >> id >> duration >> room_no >> phone_no >> address;
            if (found == 0)
            {
                cout << "\n\n\t\t\t hotel del_data No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("guestRecord.txt");
        rename("record.txt", "guestRecord.txt");
    }
}
void hotel::searchGuest() // searchGuest data of hotel
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("guestRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- hotel search Guest Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string guest_id;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- hotel search Guest Data ------------------------------------------" << endl;
        cout << "\n Enter Id No. of Guest that You Want to search: ";
        cin >> guest_id;
        file >> name >> id >> duration >> room_no >> phone_no >> address;
        while (!file.eof())
        {
            if (guest_id == id)
            {
                cout << "\n\t\t\t Guest Name: " << name << endl;
                cout << "\t\t\t  Guest Id.: " << id << endl;
                cout << "\t\t\t duration of stay (in days): " << duration << endl;
                cout << "\t\t\t Guest Room Number: " << room_no << endl;
                cout << "\t\t\t Guest Address: " << address << endl;
                found++;
            }
            file >> name >> id >> duration >> room_no >> phone_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent del_data No. Not Found...";
        }
        file.close();
    }
}
void hotel::deleteGuest()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string del_data;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Guest Details ------------------------------------------" << endl;
    file.open("guestRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Id No. of Guest that you want to Delete Data: ";
        cin >> del_data;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> duration >> room_no >> phone_no >> address;
        while (!file.eof())
        {
            if (del_data != id)
            {
                file1 << " " << name << " " << id << " " << duration << " " << room_no << " " << phone_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> duration >> room_no >> phone_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t hotel del_data NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("guestRecord.txt");
        rename("record.txt", "guestRecord.txt");
    }
}
int 
main()
{
    hotel project;
    project.menu();
    return 0;
}     
      

