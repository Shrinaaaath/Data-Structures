#include <iostream>
using namespace std;

class Node
{
public:
    int id, tasks;
    string name;
    Node* next;
};

void taskallotment (Node* head, int num)
{
        Node* temp = head;
        int counts = 0;
        int i = 1, k = 0;
        int first;
        while (counts != num)
        {
            if (temp -> tasks != 0)
            {
                cout << "Turn " << i << ": " << "Task of " << temp -> id << endl;
                temp -> tasks --;
                temp = temp -> next;
                i++;
            }

            else
            {
                if (k == 0)
                {
                    first = temp -> id;
                    k++;
                }
                temp = temp -> next;
                counts++;
            }
        }

        cout << "The task completed first is employee " << first << endl;
}
int main()
{
    int num;
    Node* head;
    Node* curr;
    Node* temp;
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

                cout << "Enter the ID of Node " << i << ": ";
                cin >> curr -> id;

                cout << "Enter the name of Node " << i << ": ";
                cin >> curr -> name;

                cout << "Enter the number of tasks alloted to " << curr -> name << ": ";
                cin >> curr -> tasks;

                cout << endl;

                curr -> next = after;
                curr = curr -> next;
            }

            else
            {
                cout << "Enter the ID of Node " << i << ": ";
                cin >> curr -> id;

                cout << "Enter the name of Node " << i << ": ";
                cin >> curr -> name;

                cout << "Enter the number of tasks alloted to " << curr -> name << ": ";
                cin >> curr -> tasks;

                cout << endl;

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

    taskallotment(head, num);
}
