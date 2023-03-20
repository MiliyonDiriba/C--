#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define the structure for a guest
struct Guest {
    int id;
    char name[50];
    char address[100];
    char phone[15];
    int roomNumber;
    int duration;
};

void addAndSaveGuest();
void display();
void searchGuest();
void updateGuest();
void deleteGuest();
void calculate();
void choice();
void choice(){
 int choice;
    do {
        cout<< "*************Hotel Management System**************\n";
        cout<<"1. Add Guest\n";
        cout<<"2. Display information\n";
        cout<<"3. Search Guest\n";
        cout<<"4. Update Guest\n";
        cout<<"5. Delete Guest\n";
        cout<<"6. Calculate Price\n";
        cout <<"7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addAndSaveGuest();
                break;
            case 2:
                display();
                break;
            case 3:
                searchGuest();
                break;
            case 7:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

}

int main() {
    choice();
    return 0;
}

void addAndSaveGuest() {
    // Create a new guest object
    Guest guest;

    // Prompt the user for the guest's information
    cout << "Enter guest ID: ";
    cin >> guest.id;
    cout << "Enter guest name: ";
    cin.ignore();
    cin.getline(guest.name, 50);
    cout << "Enter guest address: ";
    cin.getline(guest.address, 100);
    cout << "Enter guest phone number: ";
    cin.getline(guest.phone, 15);
    cout << "Enter guest room number: ";
    cin >> guest.roomNumber;
    cout << "Enter duration of stay (in days): ";
    cin >> guest.duration;

    // Open the file for writing in append mode
    ofstream file("hotels.txt", ios::app);

    // Write the guest information to the file
    file << guest.id << "," << guest.name << "," << guest.address << "," << guest.phone << "," << guest.roomNumber << "," << guest.duration << endl;

    // Close the file
    file.close();

    cout << "Guest added successfully!\n";
}
void display(){
  ifstream infile;
    infile.open("hotels.txt",ios::app);
    if (!infile) {
        cout << "Unable to open file" << endl;
        return;
    }
      
    Guest guest;
    cout << "Guests currently in the hotel:" << endl;
    cout<<"no  "<<"guest fname     "<<"guestID    "<<"guest adress    "<<" guest phone     "<<"guest room no    "<<"days"<<endl;
    while (infile >> guest.id >>guest.name >> guest.address>>guest.phone>>guest.roomNumber>>guest.duration) {
        cout << guest.id << "        "<<guest.name<<"         "<< guest.address<<"        "<<guest.phone<<"       " << guest.roomNumber<<"   " <<guest.duration<< endl;
    }

    infile.close();

}

void searchGuest() {
    // Prompt the user for the guest ID to search for
    int searchId;
    cout << "Enter guest ID to search for: ";
    cin >> searchId;

    // Open the file for reading
    ifstream file("hotels.txt");

    // Read the file line by line and search for the guest ID
    bool found = false;
    while (!file.eof()) {
        Guest guest;
        file >> guest.id;
        file.ignore();
        file.getline(guest.name, 50, ',');
        file.getline(guest.address, 100, ',');
        file.getline(guest.phone, 15, ',');
        file >> guest.roomNumber;
        file.ignore();
        file >> guest.duration;
        file.ignore();

        if (guest.id == searchId) {
            // Display the guest information
            cout << "Guest ID: " << guest.id << endl;
            cout << "Guest name: " << guest.name << endl;
            cout << "Guest address: " << guest.address << endl;
            cout << "Guest phone number: " << guest.phone << endl;
            cout << "Guest room number: " << guest.roomNumber << endl;
        cout << "Duration of stay: " << guest.duration << " days" << endl;
        found = true;
        break;
    }
}

// Close the file
file.close();

if (!found) {
    cout << "Guest not found!\n";
}
}