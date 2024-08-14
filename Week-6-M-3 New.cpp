#include <iostream>
#include<string>
using namespace std;

class Node
{
public:
    string data;
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

    void enqueue(int i)
    {
        Node* newNode = new Node();
        int j = 0;
        int bin_num[15];
        string rem = "";
        while(i > 0)
        {
            bin_num[j] = i % 2;
            i = i / 2;
            j++;
        }

        for(int k = j - 1; k >= 0; k--)
        {
            rem += to_string(bin_num[k]);
        }

        newNode -> data = rem;

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
        q1.enqueue(i);
    }

    q1.display();
}
