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

    void enqueue(int elem[])
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
};

int main()
{
    int n;
    int bin_num[15];
    intQ q1;

    cout << "Enter the range: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int j = 0;
        while(i > 0)
        {
            bin_num[j] = i % 2;
            i = i / 2;
            j++;
        }
        q1.enqueue(bin_num)
    }

    q1.display();
}
