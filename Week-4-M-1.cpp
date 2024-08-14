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
    int arr[20];
    Node* head;
    Node* curr;
    Node* temp;
    Node* curr1;
    Node* head1;
    Node* newtemp;
    int num, j = 0, k = 0;

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
                curr -> next = head;
                head -> prev = curr;
                j++;
                delete after;
            }
        }
        if (j == 1)
        {
            break;
        }
    }

    Node* result = new Node();
    Node* head2;
    int i = 0;

    do
    {
        Node* temp2 = temp -> next;
        int sum = 0;

        do
        {
            sum += temp2 -> data;
            temp2 = temp2 -> next;
        }while (temp2 != temp);
        arr[i] = sum;
        i++;

        temp = temp -> next;
    }while (temp != head);

    for (int i = 1; i <= num; i++)
    {
        Node* after1 = new Node();
        if (i == 1)
        {
            curr1 = new Node();
            head1 = curr1;
            newtemp = head1;
            curr1 -> data = arr[i - 1];
            curr1 -> prev = NULL;
            curr1 -> next = after1;
            after1 -> prev = curr1;
            curr1 = curr1 -> next;
        }

        else
        {
            curr1 -> data = arr[i - 1];

            if (i != num)
            {
                curr1 -> next = after1;
                after1 -> prev = curr1;
                curr1 = curr1 -> next;
            }

            else
            {
                curr1 -> next = head1;
                head1 -> prev = curr1;
                k++;
                delete after1;
            }
        }
        if (k == 1)
        {
            break;
        }
    }


    cout << "The elements of the New Linked List are: " << endl;
    do
    {
        cout << newtemp -> data << endl;
        newtemp = newtemp -> next;
    }while(newtemp != head1);

}
