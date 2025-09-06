// write a simple airline ticket reservation program. The program should display a menu with the following options:
// reserve a ticket, cancel a reservation, check whether a ticket is reserved for particular person, and display the
// passengers. the information is maintained on a alphabetized linked list of names. in simple version of the
// program, assume that tickets are reserved for only one flight. In a fuller version, place no limit on the number of
// flights. create a linked list of flights with each node including a pointer to a linked list of passengers

#include <iostream>
using namespace std;

struct Passenger {
    string name;
    Passenger* next;
    Passenger(const string& n) : name(n), next(nullptr) {}
};

class PassengerList {
    Passenger* head;
public:
    PassengerList() : head(nullptr) {}

    void reserveTicket(const string& name) {
        Passenger* newNode = new Passenger(name);
        if (!head || name < head->name) {
            newNode->next = head;
            head = newNode;
            cout << "Ticket reserved for " << name << endl;
            return;
        }
        Passenger* curr = head;
        while (curr->next && curr->next->name < name)
            curr = curr->next;
        if (curr->name == name || (curr->next && curr->next->name == name)) {
            cout << "Ticket already reserved for " << name << endl;
            delete newNode;
            return;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        cout << "Ticket reserved for " << name << endl;
    }

    void cancelReservation(const string& name) {
        if (!head) {
            cout << "No reservations found." << endl;
            return;
        }
        if (head->name == name) {
            Passenger* temp = head;
            head = head->next;
            delete temp;
            cout << "Reservation cancelled for " << name << endl;
            return;
        }
        Passenger* curr = head;
        while (curr->next && curr->next->name != name)
            curr = curr->next;
        if (curr->next && curr->next->name == name) {
            Passenger* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "Reservation cancelled for " << name << endl;
        } else {
            cout << "No reservation found for " << name << endl;
        }
    }

    bool isReserved(const string& name) {
        Passenger* curr = head;
        while (curr) {
            if (curr->name == name)
                return true;
            curr = curr->next;
        }
        return false;
    }

    void displayPassengers() {
        if (!head) {
            cout << "No passengers reserved." << endl;
            return;
        }
        cout << "Passenger List:" << endl;
        Passenger* curr = head;
        while (curr) {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }

    ~PassengerList() {
        while (head) {
            Passenger* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PassengerList list;
    int choice;
    string name;
    do {
        cout << "\nMenu:\n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check reservation\n";
        cout << "4. Display passengers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name;
                list.reserveTicket(name);
                break;
            case 2:
                cout << "Enter passenger name: ";
                cin >> name;
                list.cancelReservation(name);
                break;
            case 3:
                cout << "Enter passenger name: ";
                cin >> name;
                if (list.isReserved(name))
                    cout << name << " has a reservation." << endl;
                else
                    cout << name << " does not have a reservation." << endl;
                break;
            case 4:
                list.displayPassengers();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
