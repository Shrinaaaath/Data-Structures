#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* mergell(Node* head1, Node* head2)
{
    Node res1;
    Node* res;

    res = &res1;

    while(true)
    {
        if(head1 == NULL)
        {
            res -> next = head2;
            break;
        }

        else if(head2 == NULL)
        {
            res -> next = head1;
            break;
        }

        if(head1 -> data <= head2 -> data)
        {
            Node* newNode = head1;
            head1 = head1 -> next;

            newNode -> next = NULL;
            res -> next = newNode;
        }

        else
        {
            Node* newNode = head2;
            head2 = head2 -> next;

            newNode -> next = NULL;
            res -> next = newNode;
        }

        res = res -> next;
    }

    return res1.next;
}

void display(Node* head)
{
    cout << endl;
    cout << "The elements of the Linked List are: " << endl;

    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << "\t";
        temp = temp -> next;
    }

    cout << endl;
}

int main()
{
    int n1, n2;
    Node* head1;
    Node* head2;
    Node* curr1;
    Node* curr2;

    cout << "Enter the number of elements in the 1st Linked List: ";
    cin >> n1;

    cout << "Enter the number of elements in the 2st Linked List: ";
    cin >> n2;

    cout << endl << endl;
    cout << "Enter the elements of the 1st Linked List: " << endl;

    for(int i = 1; i <= n1; i++)
    {
        Node* after = new Node();
        if(i == 1)
        {
            curr1 = new Node();
            head1 = curr1;

            cout << "Element " << i << ": ";
            cin >> curr1 -> data;

            curr1 -> next = after;
            curr1 = curr1 -> next;

        }

        else
        {
            if(i != n1)
            {
                cout << "Element " << i << ": ";
                cin >> curr1 -> data;

                curr1 -> next = after;
                curr1 = curr1 -> next;
            }

            else
            {
                cout << "Element " << i << ": ";
                cin >> curr1 -> data;

                curr1 -> next = NULL;
                delete after;
            }
        }
    }

    cout << endl << endl;
    cout << "Enter the elements of the 2st Linked List: " << endl;

    for(int i = 1; i <= n2; i++)
    {
        Node* after = new Node();
        if(i == 1)
        {
            curr2 = new Node();
            head2 = curr2;

            cout << "Element " << i << ": ";
            cin >> curr2 -> data;

            curr2 -> next = after;
            curr2 = curr2 -> next;

        }

        else
        {
            if(i != n2)
            {
                cout << "Element " << i << ": ";
                cin >> curr2 -> data;

                curr2 -> next = after;
                curr2 = curr2 -> next;
            }

            else
            {
                cout << "Element " << i << ": ";
                cin >> curr2 -> data;

                curr2 -> next = NULL;
                delete after;
            }
        }
    }

    display(head1);
    display(head2);

    Node* res_head;

    res_head = mergell(head1, head2);

    display(res_head);
}
