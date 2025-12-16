#include <iostream>
using namespace std;

struct node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
public:
    node* root;
    BST(){
        root = nullptr;
    }

    bool isempty(){
        if(root == nullptr){
            return true;
        } 
        return false;
    }

    node* search(node* root, int val){
        if(root == nullptr){
            return nullptr;
        }
        if(root->data == val){
            return root;
        }
        if(val < root->data){
            return search(root->left, val);
        }else{
            return search(root->right, val);
        }
    }

    node* insert(node* root, int val){
        if(root == nullptr){
            node* newNode = new node(val);
            return newNode;
        }

        if(val < root->data){
            root->left = insert(root->left, val);
        }else if(val > root->data){
            root->right = insert(root->right, val);
        }
        return root;
    }

    node* deletenode(node* root, int val){
        if(root == nullptr){
            return root;
        }

        if(val < root->data){
            root->left = deletenode(root->left, val);
        }else if(val > root->data){
            root->right = deletenode(root->right, val);
        }else{
            if(root->left == nullptr){
                node* temp = root->right;
                delete root;
                return temp;
            }else if(root->right == nullptr){
                node* temp = root->left;
                delete root;
                return temp;
            }else{
                node* temp = root->right;
                while(temp->left != nullptr){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
        }       
        return root;
    }

    void inorder(node* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }

    void preorder(node* root){
        if(root == nullptr){
            return;
        }
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
};

int main(){
    BST tree;

    if(tree.isempty()){
        cout <<"Tree is empty\n";
    }else{
        cout<< "Tree is not empty\n";
    }
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 7);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);

    node* foundNode = tree.search(tree.root, 7);
    if(foundNode != nullptr){
        cout <<"Node found.\n";
    }else{
        cout <<"Node not found.\n";
    }

    tree.insert(tree.root, 6);
    cout <<"Preorder Traversal: ";
    tree.preorder(tree.root);
    cout <<"\n";

    tree.root = tree.deletenode(tree.root, 3);
    cout <<"Inorder Traversal after deletion: ";
    tree.inorder(tree.root);
    cout <<"\n";

    return 0;
}
