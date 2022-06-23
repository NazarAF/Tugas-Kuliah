//Program Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data; 
    Node *left;
    Node *right;
};

void insert(Node *root, char input){
    if (root == NULL){
        Node *newNode;
        newNode = new Node;
        newNode->data = input;
        newNode->right = NULL;
        newNode->left = NULL;
        root = newNode;
    } else {
        if(input < root->data){
            insert(root->left, input);
        } else {
            insert(root->right, input);
        }
    }
}

void insertRight(Node *root, char data){
    Node *temp;
    temp = root;
    if(temp->right == NULL){
        Node *newNode;
        newNode = new Node;
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        temp->right = newNode;
    } else {
        temp = temp->right;
        while (temp != NULL){
            if(temp->data > data){
                temp = temp->right;
            } else if(temp->data < data){
                temp = temp->left;
            }
        }
        Node *newNode;
        newNode = new Node;
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        temp->right = newNode;
    }
}

void insertLeft(Node *root, char data){
    Node *temp;
    temp = root;
    if(temp->left == NULL){
        Node *newNode;
        newNode = new Node;
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        temp->left = newNode;
    } else {
        temp = temp->left;
        while (temp != NULL){
            if(temp->data > data){
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        Node *newNode;
        newNode = new Node;
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        temp->left = newNode;
    }
}

void preOrder(Node *root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void menu(){
    cout << "1. Insert" << endl;
    cout << "2. Print" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

void submenu(){
    cout << "1. Pre-Order Print" << endl;
    cout << "2. In-Order Print" << endl;
    cout << "3. Post-Order Print" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Node *root;
    int choice, choice2;
    while (true){
        menu();
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter the data: ";
                char data;
                cin >> data;
                insert(root, data);
                break;
            case 2:
                while (true){
                    submenu();
                    cin >> choice2;
                    switch (choice2){
                        case 1:
                            preOrder(root);
                            cout << endl;
                            break;
                        case 2:
                            inOrder(root);
                            cout << endl;
                            break;
                        case 3:
                            postOrder(root);
                            cout << endl;
                            break;
                        case 4:
                            return 0;
                        default:
                            cout << "Invalid choice" << endl;
                    }
                }
            case 3:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
