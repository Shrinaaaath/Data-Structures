#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class intQ
{
public:
    Node* first;
    Node* last;

    intQ()
    {
        first = NULL;
        last = NULL;
    }

    void enqueue(int elem)
    {
        Node* newNode = new Node();
        newNode -> data = elem;

        if(first == NULL)
        {
            first = newNode;
            last = newNode;
        }

        else
        {
            last -> next = newNode;
            last = newNode;
        }
    }

    void dequeue()
    {
        //Queue is Empty
        if(first == NULL)
        {
            cout << "Queue is Empty!";
            return;
        }

        //Queue contains Multiple elements
        else if(first != last)
        {
            Node* temp = first;
            first = first -> next;
            delete temp;
        }

        //Queue contains only 1 element
        else
        {
            delete first;
            first = NULL;
            last = NULL;
        }
    }

    void display()
    {
        cout << endl;
        cout << "The elements of the Queue are:" << endl;

        Node* temp = first;

        while(temp != NULL)
        {
            cout << temp -> data << "\t";
            temp = temp -> next;
        }
    }

    void peek()
    {
        cout << endl;
        cout << "Queue Front: " << first -> data << endl;;
        cout << "Queue Rear: " << last -> data << endl;
    }


};

int main()
{
    int num, elem;
    intQ q1;

    cout << "Enter the number of elements to be added to the Queue: ";
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cout <<"Enter the element " << i + 1 << ": ";
        cin >> elem;
        q1.enqueue(elem);
    }

    q1.display();
    q1.peek();
    q1.dequeue();
    q1.display();
    q1.peek();
}
