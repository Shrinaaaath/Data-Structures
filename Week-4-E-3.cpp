#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

void converttodecimal (Node* curr)
{
    Node* temp = curr;
    int k = 0, res = 0;
    do
    {
        res += (pow(2, k) * temp -> data);
        temp = temp -> prev;
        k++;
    }while(temp != curr);

    cout << "Decimal: " << res;
}
int main()
{
    Node* head;
    Node* curr;
    Node* temp;
    int num, j = 0;

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

    converttodecimal(curr);
}
