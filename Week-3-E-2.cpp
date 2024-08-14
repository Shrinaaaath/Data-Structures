#include<iostream>
#include<string>
using namespace std;
class node
{
    public:
    int data2,data3;
    string data1;
    node* next;
};
void maxsalaryofemp(node* head)
{
    int max=head->data3;
    node* temp=head->next;
    while(temp!=NULL)
    {
        if(temp->data3>max)
        {
            max=temp->data3;
        }
        temp=temp->next;
    }
    cout<<"Maximum salary of the employee is "<<max<<endl;
}
int main()
{
    int id,salary;
    string name;
    int n;
    node* head=NULL;
    cout<<"Enter the number of nodes:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the name of employee:";
        cin>>name;
        cout<<"Enter the id of employeee:";
        cin>>id;
        cout<<"Enter salary of employee:";
        cin>>salary;
        node* newnode=new node();
        newnode->data1=name;
        newnode->data2=id;
        newnode->data3=salary;
        newnode->next=head;
        head=newnode;
    }
    maxsalaryofemp(head);
    return 0;
}
