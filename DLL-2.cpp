#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
    Node* prev;
};

int main()
{
    Node* head;
    Node* curr;
    Node* curr1;
    Node* temp;
    int num;

    cout << "Enter the number of nodes: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        Node* after = new Node();
        if (i == 1)
        {
            curr = new Node();
            head = curr;

            cout << "Enter the value of Node " << i << ": ";
            cin >> curr -> data;
            curr -> prev = NULL;
            curr -> next = after;
            after -> prev = curr;
            curr = curr -> next;
        }

        else
        {
            cout << "Enter the value of Node " << i << ": ";
            cin >> curr -> data;
            if (i != num)
            {
                curr -> next = after;
                after -> prev = curr;
                curr = curr -> next;
            }
            else
            {
                curr -> next = NULL;
                delete after;
            }
        }
    }

    temp = head;
    if (num % 2 == 0)
    {
        for (int i = 1; i <= (num / 2); i++)
        {
            cout << "Value = " << temp -> data << endl;
            temp = temp -> next;
        }
    }
    else
    {
        for (int i = 1; i <= (num / 2) + 1; i++)
        {
            cout << "Value = " << temp -> data << endl;
            temp = temp -> next;
        }
    }

    Node* inser = new Node();
    cout << "Enter the element to be inserted in the Middle of the Linked List: ";
    cin >> inser -> data;

    inser -> next = temp;
    temp -> prev -> next = inser;
    inser -> prev = temp -> prev;

    cout << "The elements of the new Linked List are: " << endl;

    while(head != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
}
