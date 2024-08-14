#include <iostream>
using namespace std;

class intQ
{
public:
    int data[15];
    int front = -1;
    int rear = -1;
    int size;

    intQ(int len)
    {
        size = len;
    }

    void enqueue(int elem)
    {
        if(rear == -1)
        {
            rear = 0;
            front = 0;
            data[front] = elem;
        }

        else if((rear + 1) % size == front)
        {
            cout << "Queue is Full!";
        }

        else
        {
            rear++;
            if(rear == size)
            {
                rear = 0;
            }
            data[rear] = elem;
        }
    }

    void dequeue()
    {
        if(rear == -1)
        {
            cout << "Queue is Empty!";
        }

        int value = data[front];
        cout << "The element dequeued from the Queue is " << value << endl << endl;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if (front == size-1)
            front = 0;
        else
            front++;

    }
    void display()
    {
        if(front == -1)
        {
            cout << "Queue has no Elements!" << endl;
            return;
        }

        cout << "New Queue: " << endl;
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << data[i] << "\t";
        }
        else
        {
            for (int i = front; i < size; i++)
                cout << data[i] << "\t";

            for (int i = 0; i <= rear; i++)
                cout << data[i] << "\t";
        }
    }
};

int main()
{
    int len;
    int elem;

    cout << "Enter the number of elements to be added to the Circular Queue: ";
    cin >> len;

    //Creating a Circular Queue by initializing an Object for the class
    intQ q1(len);

    //Getting inputs from the user
    for(int i = 0; i < len; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> elem;
        q1.enqueue(elem);
    }
    q1.display();

    cout << endl << endl;

    q1.dequeue();
    q1.display();
}
