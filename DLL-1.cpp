#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

int main()
{
    Node* head;
    Node* curr;
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

    temp = curr;

    Node* nnode = new Node();
    cout << "Enter the value of the node to be inserted at the end of the Linked List: ";
    cin >> nnode -> data;
    temp -> next = nnode;
    nnode -> next = NULL;

    while(head != NULL)
    {
        cout << "Element: " << head -> data << endl;
        head = head -> next;
    }
}
