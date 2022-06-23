//Program Binary Tree
#include <bits/stdc++.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

struct Node {
    char data; 
    Node *left;
    Node *right;
};

void insert(Node *&root, char data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (data <= root->data) {
            insert(root->left, data);
        } else {
            insert(root->right, data);
        }
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
    root = NULL;
    int choice, choice2;
    while (true){
        system("CLS");
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
                    cout << "Exiting..." << endl;
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
                break;
            case 3:
            cout << "Thank you for using the program" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << "Press enter to continue...";
        cin.ignore();
        cin.get();
    }
}
