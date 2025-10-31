#include <iostream>
using namespace std;
struct Node {
    int patientID;
    Node* next;
    Node* prev;
    Node(int id) {
        patientID = id;
        next = nullptr;
        prev = nullptr;
    }
};
class ERQueue {
private:
    Node* head;
    Node* tail;
public:
    ERQueue() {
        head = nullptr;
        tail = nullptr;
    }
    ~ERQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addFront(int patientID) {
        Node* newNode = new Node(patientID);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addEnd(int patientID) {
        Node* newNode = new Node(patientID);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addAt(int patientID, int pos) {
        if (pos <= 0) {
            cout << "Invalid position! Position must be positive." << endl;
            return;
        }
        if (pos == 1) {
            addFront(patientID);
            return;
        }
        Node* newNode = new Node(patientID);
        Node* current = head;
        int count = 1;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            addEnd(patientID);
        } else if (current->next == nullptr) {
            addEnd(patientID);
        } else {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    bool removeFront() {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        cout << "Patient Ended: " << temp->patientID;
        delete temp;
        return true;
    }

    void display() const {
        if (head == nullptr) {
            cout << "No patients in ER queue!" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->patientID;
            if (current->next != nullptr) cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    ERQueue list;
    int choice, id, pos;

    do {
        cout << "\n=== ER Patient Management System ===";
        cout << "\n1. Add critical patient at beginning";
        cout << "\n2. Add normal patient at end"; 
        cout << "\n3. Add patient at specific position";
        cout << "\n4. Remove treated patient from beginning";
        cout << "\n5. Display all patients";
        cout << "\n6. Exit";
        cout << "\nEnter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID: ";
                cin >> id;
                list.addFront(id);  // Updated function call
                cout << "Critical patient added. Updated ER Queue:\n";
                list.display();
                break;
                
            case 2:
                cout << "Enter patient ID: ";
                cin >> id;
                list.addEnd(id);  // Updated function call
                cout << "Normal patient added. Updated ER Queue:\n";
                list.display();
                break;
                
            case 3:
                cout << "Enter patient ID: ";
                cin >> id;
                cout << "Enter position: ";
                cin >> pos;
                list.addAt(id, pos);  // Updated function call
                cout << "Patient added at position " << pos << ". Updated ER Queue:\n";
                list.display();
                break;
                
            case 4:
                if (list.removeFront()) {  // Updated function call
                    cout << "\nPatient treated and removed from queue.\n";
                } else {
                    cout << "No patients to remove - ER queue is empty.\n";
                }
                cout << "Updated ER Queue:\n";
                list.display();
                break;
                
            case 5:
                cout << "Current ER Queue:\n";
                list.display();
                break;
                
            case 6:
                cout << "Thank you for using ER Management System. Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice! Please enter a number between 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
