#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};

void insertAtHead(Node **head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node **head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    int count = 1;
    while (temp->next != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    *head = temp->next;
    delete temp;
}

void deleteAtTail(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL)
    {
        delete temp;
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    int count = 1;
    while (temp->next != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        return;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void menu(){
    cout << "1. Insert at head" << endl;
    cout << "2. Insert at tail" << endl;
    cout << "3. Insert at position" << endl;
    cout << "4. Delete at head" << endl;
    cout << "5. Delete at tail" << endl;
    cout << "6. Delete at position" << endl;
    cout << "7. Print list" << endl;
    cout << "8. Exit" << endl;
}

int main(){
    Node *head = NULL;
    int choice, data, position;
    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            insertAtHead(&head, data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            insertAtTail(&head, data);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            insertAtPosition(&head, data, position);
            break;
        case 4:
            deleteAtHead(&head);
            break;
        case 5:
            deleteAtTail(&head);
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            deleteAtPosition(&head, position);
            break;
        case 7:
            cout << "List: ";
            printList(head);
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << endl;
    }
}