#include <iostream>
#include <string>
#include <limits>
using namespace std;

// =========================================================
// 1. NODE STRUCTURE
// =========================================================
struct TimeCapsule {
    int year;
    string eventName;
    TimeCapsule* left;
    TimeCapsule* right;

    TimeCapsule(int y, string n) : year(y), eventName(n), left(nullptr), right(nullptr) {}
};

// =========================================================
// 2. BST CLASS
// =========================================================
class TimeTree {
private:
    TimeCapsule* root;

    // =========================================================
    // (1) INSERT HELPER  – Implements BST insertion
    // =========================================================
    TimeCapsule* insertHelper(TimeCapsule* node, int year, string name) {
        if (node == nullptr)
            return new TimeCapsule(year, name);     // Create new node

        if (year < node->year)
            node->left = insertHelper(node->left, year, name);   // Go left
        else if (year > node->year)
            node->right = insertHelper(node->right, year, name); // Go right

        return node; // Return unchanged root
    }

    // =========================================================
    // (2) SEARCH HELPER – Standard BST search
    // =========================================================
    TimeCapsule* searchHelper(TimeCapsule* node, int year) {
        if (!node) return nullptr;
        if (year == node->year) return node;
        if (year < node->year) return searchHelper(node->left, year);
        return searchHelper(node->right, year);
    }

    // =========================================================
    // (3) FIND MIN (Inorder Successor)
    // =========================================================
    TimeCapsule* findMin(TimeCapsule* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // =========================================================
    // (4) DELETE HELPER – Handles all 3 delete cases
    // =========================================================
    TimeCapsule* deleteHelper(TimeCapsule* node, int year) {
        if (!node) return nullptr;

        if (year < node->year)
            node->left = deleteHelper(node->left, year);
        else if (year > node->year)
            node->right = deleteHelper(node->right, year);
        else {
            // Case 1: Leaf
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            else if (!node->left) {
                TimeCapsule* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                TimeCapsule* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            TimeCapsule* successor = findMin(node->right);
            node->year = successor->year;
            node->eventName = successor->eventName;
            node->right = deleteHelper(node->right, successor->year);
        }
        return node;
    }

    // =========================================================
    // (5) INORDER TRAVERSAL for REPORT
    // =========================================================
    void inorder(TimeCapsule* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->year << " → " << node->eventName << endl;
        inorder(node->right);
    }

    // =========================================================
    // Destroy the entire tree (Destructor helper)
    // =========================================================
    void destroyTree(TimeCapsule* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:

    TimeTree() { root = nullptr; }
    ~TimeTree() { destroyTree(root); }

    // =========================================================
    // (6) INJECT – Public insert using helper
    // =========================================================
    void inject(int year, string name) {
        cout << "> System: Injecting " << year << "... ";
        root = insertHelper(root, year, name);
        cout << "Timeline stable." << endl;
    }

    // =========================================================
    // (7) PARADOX – Public delete using helper
    // =========================================================
    void resolveParadox(int year) {
        cout << "> Alert: Paradox detected at " << year << "!" << endl;

        if (!searchHelper(root, year)) {
            cout << "> System: Year not found. No paradox removed." << endl;
            return;
        }

        root = deleteHelper(root, year);
        cout << "> System: Paradox resolved. Year removed." << endl;
    }

    // =========================================================
    // (8) SEARCH – Uses searchHelper
    // =========================================================
    void search(int year) {
        cout << "> Query: Searching for " << year << "..." << endl;

        TimeCapsule* result = searchHelper(root, year);
        if (result)
            cout << "> Result: Event Found! [" << result->year << ": " << result->eventName << "]" << endl;
        else
            cout << "> Result: Year not found." << endl;
    }

    // =========================================================
    // (9) REPORT – Uses inorder() to print ASC years
    // =========================================================
    void report() {
        cout << "> COMMAND: CHRONOLOGICAL REPORT" << endl;
        cout << "-------------------------------" << endl;
        inorder(root);
        cout << "-------------------------------" << endl;
    }

    // =========================================================
    // (10) TIME SPAN – Bonus Feature
    // =========================================================
    void calculateTimeSpan() {
        if (!root) {
            cout << "> TimeSpan: Tree empty." << endl;
            return;
        }

        TimeCapsule* minNode = root;
        while (minNode->left) minNode = minNode->left;

        TimeCapsule* maxNode = root;
        while (maxNode->right) maxNode = maxNode->right;

        cout << "> TimeSpan: " << (maxNode->year - minNode->year) << " years." << endl;
    }
};

// =========================================================
// 3. MAIN PROGRAM (unchanged)
// =========================================================
int main() {
    TimeTree chronos;
    string command;
    int year;
    string eventName;

    cout << "--- CHRONOS TIME STABILIZER V1.0 ---" << endl;
    cout << "Waiting for Time Stream Inputs..." << endl << endl;

    while (cin >> command) {
        if (command == "INJECT") {
            cin >> year;
            getline(cin >> ws, eventName);
            chronos.inject(year, eventName);
        }
        else if (command == "PARADOX") {
            cin >> year;
            chronos.resolveParadox(year);
        }
        else if (command == "SEARCH") {
            cin >> year;
            chronos.search(year);
        }
        else if (command == "REPORT") {
            chronos.report();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "> Unknown Command." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;
    }

    return 0;
}
