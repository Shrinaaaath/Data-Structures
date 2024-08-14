#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

void pairwiseswap (Node* head, int num)
{
    Node* temp = head;
    int tmp;

    cout << "The elements of the Linked List after pairwise swapping: " << endl;

    if (num % 2 == 0)
    {
        do
        {
            tmp = temp -> data;
            temp -> data = temp -> next -> data;
            temp -> next -> data = tmp;

            cout << temp -> data << " <-> ";
            cout << temp -> next -> data << " <-> ";
            temp = temp -> next -> next;
        }while(temp != head);
    }

    else
    {
        do
        {
            tmp = temp -> data;
            temp -> data = temp -> next -> data;
            temp -> next -> data = tmp;

            cout << temp -> data << " <-> ";
            cout << temp -> next -> data << " <-> ";
            temp = temp -> next -> next;
        }while(temp -> next != head);

        cout << temp -> data << " <-> ";
    }
}

int main()
{
    Node* head;
    Node* curr;
    Node* temp;
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

    cout << "The elements of the Linked List are: " << endl;
    do
    {
        cout << temp -> data << " <-> ";
        temp = temp -> next;
    }while(temp != head);

    cout << endl;

    pairwiseswap(head, num);

}
