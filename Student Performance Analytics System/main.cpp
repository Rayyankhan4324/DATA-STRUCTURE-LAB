#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct Student {
    int id;
    string name;
    string dept;
    int semester;
    double cgpa;
    int credits;
    int year;
};

struct Node {
    Student data;
    Node* next;

    Node(Student s) {
        data = s;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(Student s) {
        Node* n = new Node(s);
        n->next = head;
        head = n;
    }

    Node* getHead() const {
        return head;
    }

  
    LinkedList clone() const {
        LinkedList copy;
        Node* temp = head;
        while (temp != nullptr) {
            copy.insert(temp->data);
            temp = temp->next;
        }
        return copy;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
void loadData(const string& filename, LinkedList& list) {
    ifstream file(filename);
    if (!file) return;

    int total;
    file >> total;
    file.ignore();

    for (int i = 0; i < total; i++) {
        Student s;

        file >> s.id;
        file.ignore();

        getline(file, s.name, ' ');
        getline(file, s.name, ' ');

        file >> s.dept >> s.semester >> s.cgpa >> s.credits >> s.year;

        if (s.cgpa >= 0.0 && s.cgpa <= 4.0 &&
            s.semester >= 1 && s.semester <= 8)
            list.insert(s);
    }
    file.close();
}
void bubbleSortCGPA(Node* head) {
    bool swapped;
    do {
        swapped = false;
        Node* cur = head;
        while (cur && cur->next) {
            if (cur->data.cgpa < cur->next->data.cgpa ||
               (cur->data.cgpa == cur->next->data.cgpa &&
                cur->data.credits < cur->next->data.credits)) {

                swap(cur->data, cur->next->data);
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
}
Node* insertionSortYear(Node* head) {
    Node* sorted = nullptr;

    while (head) {
        Node* cur = head;
        head = head->next;

        if (!sorted || cur->data.year < sorted->data.year) {
            cur->next = sorted;
            sorted = cur;
        } else {
            Node* temp = sorted;
            while (temp->next &&
                  (temp->next->data.year < cur->data.year ||
                  (temp->next->data.year == cur->data.year &&
                   temp->next->data.id < cur->data.id)))
                temp = temp->next;

            cur->next = temp->next;
            temp->next = cur;
        }
    }
    return sorted;
}
void writeRankedByCGPA(Node* head) {
    ofstream out("ranked_by_cgpa.txt");

    out << "====================================================\n";
    out << "        STUDENTS RANKED BY CGPA\n";
    out << "====================================================\n";
    out << "Rank | ID | Name | Dept | Sem | CGPA | Credits | Year\n";

    int rank = 1;
    while (head) {
        out << setw(4) << rank++ << " | "
            << head->data.id << " | "
            << head->data.name << " | "
            << head->data.dept << " | "
            << head->data.semester << " | "
            << fixed << setprecision(2) << head->data.cgpa << " | "
            << head->data.credits << " | "
            << head->data.year << "\n";
        head = head->next;
    }
    out.close();
}
int main() {
    LinkedList masterList;


    loadData("students_data.txt", masterList);

   
    LinkedList cgpaList = masterList.clone();

    
    bubbleSortCGPA(cgpaList.getHead());

    writeRankedByCGPA(cgpaList.getHead());

    return 0;
}
