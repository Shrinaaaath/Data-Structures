#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* insertatfront (Node* head)
{
    Node* temp = head;
    Node* inser = new Node();

    cout << "Enter the value of the Node to be inserted: ";
    cin >> inser -> data;

    inser -> next = temp;
    temp = inser -> next;

    while (temp -> next != head)
    {
        temp = temp -> next;
    }

    temp -> next = inser;
    head = inser;
    Node* temp2 = head;

    cout << "The elements of the Linked List after inserting at the beginning: " << endl;

    do
    {
        cout << temp2 -> data << " -> ";
        temp2 = temp2 -> next;
    }while (temp2 != head);

    cout << endl;
    cout << endl;

    return head;
}

Node* insertatend (Node* head)
{
    Node* temp = head;
    Node* temp2= head;

    do
    {
        temp = temp -> next;
    }while (temp -> next != head);

    Node* inser = new Node();

    cout << "Enter the value of the Node to be inserted: ";
    cin >> inser -> data;

    temp -> next = inser;
    inser -> next = head;

    cout << "The elements of the Linked List after inserting at the end: " << endl;

    do
    {
        cout << temp2 -> data << " -> ";
        temp2 = temp2 -> next;
    }while (temp2 != head);

    cout << endl;
    cout << endl;

    return head;
}

Node* insertatpos (Node* head)
{
    Node* temp = head;
    Node* temp2 = head;
    int pos;

    Node* inser = new Node();
    cout << "Enter the value of the Node to be inserted: ";
    cin >> inser -> data;

    cout << "Enter the position at which the Node has to be inserted: ";
    cin >> pos;

     if (pos == 1)
    {
        do
        {
            temp = temp -> next;
        }while(temp -> next != head);

        temp -> next = inser;
        inser -> next = head;
        head = inser;
        temp2 = head;
    }

    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp -> next;
        }

        inser -> next = temp -> next;
        temp -> next = inser;
    }

    cout << "The elements of the Linked List after inserting at the given position: " << endl;
    do
    {
        cout << temp2 -> data << " -> ";
        temp2 = temp2 -> next;
    }while (temp2 != head);

    cout << endl;

    return head;


}
int main()
{
    int num;
    Node* head;
    Node* temp;
    Node* curr;
    cout << "Enter the number of nodes: ";
    cin >> num;

        for (int i = 1; i <= num; i++)
        {
            Node* after = new Node();

            if (i == 1)
            {
                curr = new Node();
                head = curr;
                temp = head;

                cout << "Enter the value of Node " << i << ": ";
                cin >> curr -> data;

                curr -> next = after;
                curr = curr -> next;
            }

            else
            {
                cout << "Enter the value of Node " << i << ": ";
                cin >> curr -> data;

                if (i != num)
                {
                    curr -> next = after;
                    curr = curr -> next;
                }

                else
                {
                    curr -> next = head;
                }
            }
        }

        cout << endl;
    head = insertatfront(head);
    head = insertatend(head);
    head = insertatpos(head);
}
