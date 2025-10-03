#include <iostream>
using namespace std;

struct Node
{
    int Value;
    Node* next;

    Node(int number)
    {
        Value = number; 
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node* current = head;
        while (current)
        {
            Node* nxt = current->next;
            delete current;
            current = nxt;
        }
    }

    void insert_at_beginning(int number)
    {
        Node* NNode = new Node(number);
        NNode->next = head;
        head = NNode;
    }

    void insert_at_end(int number)
    {
        Node* NNode = new Node(number);

        if (head == nullptr)
        {
            head = NNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = NNode;
    }

    void insert_at_position(int number, int position)
    {
        Node* NNode = new Node(number);
        if (position == 0)
        {
            insert_at_beginning(number);
            return;
        }

        Node* current = head;

        for (int i = 0; current != nullptr && i < position - 1; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Position Out Of Range. Inserting At End.\n";
            insert_at_end(number);
            return;
        }
        
        NNode->next = current->next;
        current->next = NNode;
    }

    void delete_from_beginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void print()
    {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr)
        {
            cout << current->Value << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }
};

int main()
{
    LinkedList queue;

    cout << "Starting Operations:\n";
    queue.insert_at_beginning(101);
    queue.print();

    queue.insert_at_end(102);
    queue.insert_at_end(103);
    queue.print();

    queue.insert_at_beginning(999);
    queue.print();

    queue.insert_at_position(555, 2); 
    queue.print(); 

    queue.delete_from_beginning();
    queue.print();

    return 0;
}