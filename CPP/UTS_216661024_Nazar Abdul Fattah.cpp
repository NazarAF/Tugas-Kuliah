#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Nazar Abdul Fattah - 216661024

struct Node
{
    char data;
    Node *next;
};

bool Validate(Node *head, char data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Sort(Node *&head)
{
    Node *temp = head;
    Node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        while (next != NULL)
        {
            if (temp->data > next->data)
            {
                char tempData = temp->data;
                temp->data = next->data;
                next->data = tempData;
            }
            next = next->next;
        }
        temp = temp->next;
    }
}

void Push(Node **head, char data)
{
    if(*head == NULL)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
    }
    Sort(*head);
    cout << "Data berhasil dimasukan";
}

void Pop(Node **head, char data)
{
    if(Validate(*head, data))
    {
        Node *temp = *head;
        if (temp->data == data)
        {
            *head = temp->next;
            delete temp;
            cout << "Data " << data << " berhasil dihapus";
            return;
        }

        while (temp->next != NULL && temp->data != data)
        {
            if (temp->next->data == data)
            {
                Node *temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                cout << "Data " << data << " berhasil dihapus";
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
    } 
    else
    {
        cout << "Data tidak ada";
    }
}

void Print(Node *head)
{
    Node *temp = head;
    cout << "List : ";
    if (temp == NULL)
    {
        cout << "List kosong";
    }
    else {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

void menu() {
    cout << "==== Menu ====" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Print" << endl;
    cout << "==============" << endl;
    cout << "0. Exit" << endl;
    cout << "==============" << endl;
}

char form() {
    char data;
    cout << "Masukkan data: ";
    cin >> data;
    return data;
}

int main(){
    Node *head = NULL;
    char data;
    int choice;
    while (true)
    {
        menu();
        cout << "Masukkan pilihan: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                data = form();
                Push(&head, data);
                break;
            case 2:
                data = form();
                Pop(&head, data);
                break;
            case 3:
                Print(head);
                break;
            case 0:
                cout << "Program berhenti" << endl;
                return 0;
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
        }
        cout << endl;
    }
}