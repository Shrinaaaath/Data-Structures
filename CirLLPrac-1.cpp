#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

//As I am calling the Display Function from the insertatnpos function,
//I have to inform the compiler that a function named display is written somewhere else in the program
//This is known as function prototyping :(
Node* insertatnpos(Node*);
void display(Node*);

Node* insertatnpos(Node* head)
{
    int pos;
    char ans;

    //Asking the user for the position at which the element has to be inserted
    cout << endl;
    cout << "Enter the position in which the element has to be inserted from the current position: ";
    cin >> pos;

    //We need this duplicate variable to store the value of pos, as we are going to modify it later
    int dup = pos;


    Node* temp = head;

    //I have used a do while loop to let user control the number of insertions to be performed:)
    do
    {
        Node* inser;

        //This is a Special Case
        //Because if pos == 1 it means that we have to insert the element just before the curr element
        if(pos == 1)
        {
            Node* temp2 = temp;

            while(temp2 -> next != temp)
            {
                temp2 = temp2 -> next;
            }

            inser = new Node();
            cout << endl;
            cout << "Enter the value of the Node to be inserted: ";
            cin >> inser -> data;

            //This case occurs when the position in which our element needs to inserted
            //happens to be the very first element
            //In such a case, we have to modify the head !!!

            if(temp == head)
            {
                //Head has been modified :)
                head = inser;
            }
            temp2 -> next = inser;
            inser -> next = temp;
        }

        //Position to be inserted is not the 1
        else
        {
            //If I have to reach the nth position then I have to perform n - 2 jumps
            //Eg: If there are 5 elements in the LL
            //1 -> 2 -> 3 -> 4 -> 5
            //If I am currently at the 1st node
            //Suppose i have to reach the 3rd pos from the current node, I have to perform only a single jump
            //Means my current has to be moved to the 2nd node, and the element to be inserted,
            //can be done after it.
            while(pos > 2)
            {
                temp = temp -> next;
                pos--;
            }


            //Asking the user for the element which has to be inserted
            inser = new Node();
            cout << endl;
            cout << "Enter the value of the Node to be inserted: ";
            cin >> inser -> data;

            //If the position we are trying to insert happens to be the first position
            //Then we have to modify the head !!!
            if(temp -> next == head)
            {
                //Head has been modified
                head = inser;
            }
            inser -> next = temp -> next;
            temp -> next = inser;
        }

        display(head);

        //As Position has been decremented in the above Loop
        //We have to change it back to its original value
        //As we have a duplicate, we don't have to worry about it :)

        pos = dup;

        //Asking the user whether they wish to continue the process
        cout << endl;
        cout << "Do you wish to continue the process (Y/N) ? " << endl << "Ans: ";
        cin >> ans;

        temp = inser;
    }while(ans == 'Y' || ans == 'y');

    return head;
}

void display(Node* head)
{
    cout << endl;
    cout << "The elements of the Linked List are: " << endl;

    Node* temp = head;

    do
    {
        cout << temp -> data << "\t";
        temp = temp -> next;
    }while(temp != head);

    cout << endl;
}


int main()
{
    int num, elem;
    Node* head;
    Node* curr;

    cout << "Enter the number of elements to added to the Linked List: ";
    cin >> num;

    //Getting initial elements of the Linked List
    for(int i = 1; i <= num; i++)
    {
        Node* after = new Node();

        //First element of the Linked List
        //We have to modify the head
        //So we need this block of code:)
        if(i == 1)
        {
            cout << "Enter the value of Node " << i << ": ";
            cin >> elem;

            //If the Linked List has only One element
            //Then the head had to point to itself
            //I have freed the memory which was allocated for the after node, as we don't need it
            if(i == 1 && num == 1)
            {
                curr = new Node();
                curr -> data = elem;
                head = curr;
                curr -> next = head;
                delete after;
            }

            //We are at the First Node, but there are more elements, then the head should not point to itself
            else
            {
                curr = new Node();
                curr -> data = elem;
                head = curr;
                curr -> next = after;
                curr = curr -> next;
            }
        }

        //We are not at the First Node
        else
        {
            cout << "Enter the value of Node " << i << ": ";
            cin >> elem;

            curr -> data = elem;

            //We are not at the Last Node yet!
            if(i != num)
            {
                curr -> next = after;
                curr = curr -> next;
            }

            //We are at the last node!
            //So it's time to change the current node's next to point to the head:)
            //Don't need after node, hence kill it
            else
            {
                curr -> next = head;
                delete after;
            }
        }
    }

    display(head);
    head = insertatnpos(head);
}
