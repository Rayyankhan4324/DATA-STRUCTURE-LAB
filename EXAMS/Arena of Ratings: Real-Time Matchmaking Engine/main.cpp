#include <iostream>
#include <string>
using namespace std;

struct Node {
    int rating;
    string name;
    long long hp;
    Node* left;
    Node* right;

    Node(int r, string n, long long h) {
        rating = r;
        name = n;
        hp = h;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    int total;

    BST() {
        root = nullptr;
        total = 0;
    }

    // ---------- SEARCH ----------
    Node* search(Node* node, int r) {
        if (!node) return nullptr;
        if (node->rating == r) return node;
        if (r < node->rating) return search(node->left, r);
        return search(node->right, r);
    }

    // ---------- INSERT ----------
    Node* insert(Node* node, int r, string n, long long h, bool &ok) {
        if (!node) {
            ok = true;
            return new Node(r, n, h);
        }
        if (r < node->rating)
            node->left = insert(node->left, r, n, h, ok);
        else if (r > node->rating)
            node->right = insert(node->right, r, n, h, ok);
        else
            ok = false;
        return node;
    }

    // ---------- FIND MIN ----------
    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // ---------- DELETE ----------
    Node* remove(Node* node, int r, bool &ok) {
        if (!node) return nullptr;

        if (r < node->rating)
            node->left = remove(node->left, r, ok);
        else if (r > node->rating)
            node->right = remove(node->right, r, ok);
        else {
            ok = true;
            if (!node->left) {
                Node* t = node->right;
                delete node;
                return t;
            }
            if (!node->right) {
                Node* t = node->left;
                delete node;
                return t;
            }
            Node* t = findMin(node->right);
            node->rating = t->rating;
            node->name = t->name;
            node->hp = t->hp;
            node->right = remove(node->right, t->rating, ok);
        }
        return node;
    }

    // ---------- NEXT ----------
    Node* next(Node* node, int x) {
        Node* ans = nullptr;
        while (node) {
            if (node->rating > x) {
                ans = node;
                node = node->left;
            } else
                node = node->right;
        }
        return ans;
    }

    // ---------- PREV ----------
    Node* prev(Node* node, int x) {
        Node* ans = nullptr;
        while (node) {
            if (node->rating < x) {
                ans = node;
                node = node->right;
            } else
                node = node->left;
        }
        return ans;
    }

    // ---------- RANGE ----------
    void range(Node* node, int L, int R, bool &found) {
        if (!node) return;
        if (node->rating > L) range(node->left, L, R, found);
        if (node->rating >= L && node->rating <= R) {
            cout << node->rating << " " << node->name << " " << node->hp << "\n";
            found = true;
        }
        if (node->rating < R) range(node->right, L, R, found);
    }

    // ---------- RANK ----------
    int rank(Node* node, int x) {
        if (!node) return 0;
        if (node->rating >= x)
            return rank(node->left, x);
        return 1 + count(node->left) + rank(node->right, x);
    }

    int count(Node* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    // ---------- KTH ----------
    Node* kth(Node* node, int k) {
        if (!node) return nullptr;
        int leftCount = count(node->left);
        if (k == leftCount + 1) return node;
        if (k <= leftCount) return kth(node->left, k);
        return kth(node->right, k - leftCount - 1);
    }

    // ---------- HEIGHT ----------
    int height(Node* node) {
        if (!node) return -1;
        return 1 + max(height(node->left), height(node->right));
    }

    // ---------- LEAVES ----------
    int leaves(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return leaves(node->left) + leaves(node->right);
    }

    // ---------- DUEL ----------
    int duel(Node* node, int a, int b) {
        Node* lca = LCA(node, a, b);
        return dist(lca, a) + dist(lca, b);
    }

    Node* LCA(Node* node, int a, int b) {
        if (!node) return nullptr;
        if (node->rating > a && node->rating > b)
            return LCA(node->left, a, b);
        if (node->rating < a && node->rating < b)
            return LCA(node->right, a, b);
        return node;
    }

    int dist(Node* node, int x) {
        if (node->rating == x) return 0;
        if (x < node->rating) return 1 + dist(node->left, x);
        return 1 + dist(node->right, x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST bst;
    int Q;
    cin >> Q;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "JOIN") {
            int r; string n; long long h;
            cin >> r >> n >> h;
            bool ok = false;
            bst.root = bst.insert(bst.root, r, n, h, ok);
            if (ok) { cout << "JOINED\n"; bst.total++; }
            else cout << "DUPLICATE\n";
        }

        else if (cmd == "LEAVE") {
            int r; cin >> r;
            bool ok = false;
            bst.root = bst.remove(bst.root, r, ok);
            if (ok) { cout << "LEFT\n"; bst.total--; }
            else cout << "NOT FOUND\n";
        }

        else if (cmd == "STATUS") {
            int r; cin >> r;
            Node* p = bst.search(bst.root, r);
            if (!p) cout << "NOT FOUND\n";
            else cout << p->rating << " " << p->name << " " << p->hp << "\n";
        }

        else if (cmd == "DAMAGE") {
            int r; long long a;
            cin >> r >> a;
            Node* p = bst.search(bst.root, r);
            if (!p) cout << "NOT FOUND\n";
            else {
                p->hp = max(0LL, p->hp - a);
                cout << "DAMAGED " << p->hp << "\n";
            }
        }

        else if (cmd == "HEAL") {
            int r; long long a;
            cin >> r >> a;
            Node* p = bst.search(bst.root, r);
            if (!p) cout << "NOT FOUND\n";
            else {
                p->hp += a;
                cout << "HEALED " << p->hp << "\n";
            }
        }

        else if (cmd == "NEXT") {
            int x; cin >> x;
            Node* p = bst.next(bst.root, x);
            if (!p) cout << "NONE\n";
            else cout << p->rating << " " << p->name << " " << p->hp << "\n";
        }

        else if (cmd == "PREV") {
            int x; cin >> x;
            Node* p = bst.prev(bst.root, x);
            if (!p) cout << "NONE\n";
            else cout << p->rating << " " << p->name << " " << p->hp << "\n";
        }

        else if (cmd == "MATCH") {
            int x; cin >> x;
            if (!bst.root) {
                cout << "EMPTY\n";
                continue;
            }
            Node* p = bst.prev(bst.root, x);
            Node* s = bst.next(bst.root, x);
            if (!p && s) cout << s->rating << " " << s->name << " " << s->hp << "\n";
            else if (p && !s) cout << p->rating << " " << p->name << " " << p->hp << "\n";
            else {
                if (abs(x - p->rating) <= abs(s->rating - x))
                    cout << p->rating << " " << p->name << " " << p->hp << "\n";
                else
                    cout << s->rating << " " << s->name << " " << s->hp << "\n";
            }
        }

        else if (cmd == "RANGE") {
            int L, R; cin >> L >> R;
            bool found = false;
            bst.range(bst.root, L, R, found);
            if (!found) cout << "EMPTY\n";
        }

        else if (cmd == "RANK") {
            int x; cin >> x;
            cout << bst.rank(bst.root, x) << "\n";
        }

        else if (cmd == "KTH") {
            int k; cin >> k;
            if (k < 1 || k > bst.total) cout << "OUT OF RANGE\n";
            else {
                Node* p = bst.kth(bst.root, k);
                cout << p->rating << " " << p->name << " " << p->hp << "\n";
            }
        }

        else if (cmd == "DUEL") {
            int a, b; cin >> a >> b;
            if (!bst.search(bst.root, a) || !bst.search(bst.root, b))
                cout << "NOT FOUND\n";
            else
                cout << "DIST " << bst.duel(bst.root, a, b) << "\n";
        }

        else if (cmd == "STATS") {
            cout << "PLAYERS " << bst.total << "\n";
            if (!bst.root) {
                cout << "MIN NONE\nMAX NONE\nHEIGHT -1\nLEAVES 0\n";
            } else {
                cout << "MIN " << bst.findMin(bst.root)->rating << "\n";
                Node* t = bst.root;
                while (t->right) t = t->right;
                cout << "MAX " << t->rating << "\n";
                cout << "HEIGHT " << bst.height(bst.root) << "\n";
                cout << "LEAVES " << bst.leaves(bst.root) << "\n";
            }
        }
    }
    return 0;
}
