#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

int main()
{
    int num;
    Node* head;
    Node* temp;
    Node* temp2;
    Node* curr;
    cout << "Enter the number of nodes: ";
    cin >> num;

    if (num > 1)
    {
        for (int i = 1; i <= num; i++)
        {
            Node* after = new Node();

            if (i == 1)
            {
                curr = new Node();
                head = curr;
                temp = head;
                temp2 = head;

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

        do
        {
            cout << "Element: " << temp2 -> data << endl;
            temp2 = temp2 -> next;
        }while (temp2 != head);


        int key;

        cout << "Enter the value to be deleted from the Linked List: ";
        cin >> key;

        if (temp -> data == key)
        {
            head = temp -> next;
            temp2 = head;
            curr -> next = head;
            delete temp;
        }

        else
        {
            while (temp -> next -> data != key && temp -> next != head)
            {
                temp = temp -> next;
            }
            Node* del = temp -> next;
            temp -> next = temp -> next -> next;
            delete del;
        }

        do
        {
            cout << "Element: " << temp2 -> data << endl;
            temp2 = temp2 -> next;
        }while (temp2 != head);
    }

    else if (num == 0)
    {
        head = NULL;
        cout << "No Elements are there in the Linked List !";
        exit(0);
    }

    if (num == 1)
    {
        int key;
        Node* one = new Node();
        head = one;
        cout << "Enter the element: ";
        cin >> one -> data;
        one -> next = head;

        cout << "Enter the element to be deleted from the Linked List: ";
        cin >> key;

        if (one -> data == key)
        {
            cout << "There are no Elements in the Linked List !";

        }
        else
        {
            cout << "Element: " << one -> data << endl;
        }
    }
}
