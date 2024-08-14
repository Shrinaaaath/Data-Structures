#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
void removeduplicates(node* head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp=temp->next;
        }
    }
}
void printlist(node* n)
{
    node* var=n;
    while(var!=NULL)
    {
        cout<<var->data<<"->";
        var=var->next;
    }
    cout<<"end"<<endl;
}
int main()
{
    node* head=NULL;
    node* second=NULL;
    node* third=NULL;
    node* four=NULL;
    node* five=NULL;
    node* six=NULL;

    head=new node();
    second=new node();
    third=new node();
    four=new node();
    five=new node();
    six=new node();

    head->data=11;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=11;
    third->next=four;
    four->data=21;
    four->next=five;
    five->data=43;
    five->next=six;
    six->data=60;
    six->next=NULL;
    cout << "Current Linked List: " << endl;
    printlist(head);

    removeduplicates(head);
    cout << "Modified Linked List: " << endl;
    printlist(head);
    return 0;
}
