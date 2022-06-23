#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    string namaMahasiswa;
    int nimMahasiswa;
    string prodiMahasiswa;
    char kelasMahasiswa;
    Node *next, *prev;
};

void printList(Node *head)
{
    Node *temp = head;
    int count = 1;
    cout << "List : " << endl;
    while (temp != NULL)
    {
        cout << count << ". " << temp->namaMahasiswa << " " << temp->nimMahasiswa << " " << temp->prodiMahasiswa << " " << temp->kelasMahasiswa << endl;
        temp = temp->next;
        count++;
    }
    cout << endl;
}

void insertAtHead(Node **head, string namaMahasiswa, int nimMahasiswa, string prodiMahasiswa, char kelasMahasiswa)
{
    Node *newNode = new Node;
    newNode->namaMahasiswa = namaMahasiswa;
    newNode->nimMahasiswa = nimMahasiswa;
    newNode->prodiMahasiswa = prodiMahasiswa;
    newNode->kelasMahasiswa = kelasMahasiswa;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtTail(Node **head, string namaMahasiswa, int nimMahasiswa, string prodiMahasiswa, char kelasMahasiswa)
{
    Node *newNode = new Node;
    newNode->namaMahasiswa = namaMahasiswa;
    newNode->nimMahasiswa = nimMahasiswa;
    newNode->prodiMahasiswa = prodiMahasiswa;
    newNode->kelasMahasiswa = kelasMahasiswa;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}

void insertAtPosition(Node **head, string namaMahasiswa, int nimMahasiswa, string prodiMahasiswa, char kelasMahasiswa, int position)
{
    Node *newNode = new Node;
    newNode->namaMahasiswa = namaMahasiswa;
    newNode->nimMahasiswa = nimMahasiswa;
    newNode->prodiMahasiswa = prodiMahasiswa;
    newNode->kelasMahasiswa = kelasMahasiswa;
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
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
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
    if (temp->next != NULL)
    {
        temp->next->prev = NULL;
    }
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
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void menu()
{
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at Tail" << endl;
    cout << "3. Insert at Position" << endl;
    cout << "4. Delete at Head" << endl;
    cout << "5. Delete at Tail" << endl;
    cout << "6. Delete at Position" << endl;
    cout << "7. Print List" << endl;
    cout << "8. Exit" << endl;
}

int main(){
    Node *head = NULL;
    int choice, pos;
    string namaMahasiswa, prodiMahasiswa;
    int nimMahasiswa;
    char kelasMahasiswa;
    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter Nama: ";
            cin >> namaMahasiswa;
            cout << "Enter NIM: ";
            cin >> nimMahasiswa;
            cout << "Enter Prodi: ";
            cin >> prodiMahasiswa;
            cout << "Enter Kelas: ";
            cin >> kelasMahasiswa;
            insertAtHead(&head, namaMahasiswa, nimMahasiswa, prodiMahasiswa, kelasMahasiswa);
            break;
        case 2:
            cout << "Enter Nama: ";
            cin >> namaMahasiswa;
            cout << "Enter NIM: ";
            cin >> nimMahasiswa;
            cout << "Enter Prodi: ";
            cin >> prodiMahasiswa;
            cout << "Enter Kelas: ";
            cin >> kelasMahasiswa;
            insertAtTail(&head, namaMahasiswa, nimMahasiswa, prodiMahasiswa, kelasMahasiswa);
            break;
        case 3:
            cout << "Enter Name: ";
            cin >> namaMahasiswa;
            cout << "Enter NIM: ";
            cin >> nimMahasiswa;
            cout << "Enter Prodi: ";
            cin >> prodiMahasiswa;
            cout << "Enter Kelas: ";
            cin >> kelasMahasiswa;
            cout << "Enter Position: ";
            cin >> pos;
            insertAtPosition(&head, namaMahasiswa, nimMahasiswa, prodiMahasiswa, kelasMahasiswa, pos);
            break;
        case 4:
            deleteAtHead(&head);
            break;
        case 5:
            deleteAtTail(&head);
            break;
        case 6:
            cout << "Enter Position: ";
            cin >> pos;
            deleteAtPosition(&head, pos);
            break;
        case 7:
            printList(head);
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}