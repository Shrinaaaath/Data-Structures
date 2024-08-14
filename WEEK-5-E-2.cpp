#include<iostream>
#include<string>
using namespace std;
class node
{
    public:
  string data1;
  int data2;
  string data3;
  node* next;
};
class stustack
{
    public:
  node *top; 
  stustack()
  {
      top=NULL;
  }
  //pushing datas into stack using linked list
  void push(string name ,int id ,string depart)
  {
      node* newnode=new node();
      newnode->data1=name;
      newnode->data2=id;
      newnode->data3=depart;
      newnode->next=top;
      top=newnode;
  }
  //pop data from stack
  void pop()
  {
      if(top==NULL)
      {
          cout<<"stack is empty"<<endl;
      }
      else
      {
          node* temp=top;
          top=top->next;
          delete temp;
      }
  }
  //peeke data in the stack
  void peek()
  {
      if(top==NULL)
      {
          cout<<"stack is empty"<<endl;
      }
      else
      {
          cout<<"peek name is:"<<top->data1<<" "<<"peek id is:"<<top->data2<<" "<<"peek department is:"<<top->data3<<endl;
      }
  }
  //displaying the datas
  void display()
  {
      node* temp=top;
      if(top==NULL)
      {
          cout<<"stack is empty"<<endl;
      }
      cout<<endl;
      cout<<"details of the students"<<endl;
      while(temp!=NULL)
      {
          cout<<temp->data1<<" "<<temp->data2<<" "<<temp->data3<<endl;
          temp=temp->next;
      }
  }
};
int main()
{
    stustack sst;
    string name,depart;
    int id;
    cout<<"PUSHED DATAS ARE"<<endl;
    cout<<"Enter name,id,department for 1st student:";
    cin>>name;
    cin>>id;
        cin>>depart;
    sst.push(name,id,depart);
     cout<<"Enter name,id,department for 2nd student:";
    cin>>name;
    cin>>id;
        cin>>depart;
        sst.push(name,id,depart);

     cout<<"Enter name,id,department for 3rd student:";
    cin>>name;
    cin>>id;
        cin>>depart;
        sst.push(name,id,depart);

     cout<<"Enter name,id,department for 4th student:";
    cin>>name;
    cin>>id;
    cin>>depart;
        sst.push(name,id,depart);

     cout<<"Enter name,id,department for 5th student:";
    cin>>name;
    cin>>id;
    cin>>depart;
        sst.push(name,id,depart);
    sst.display();    
    cout<<endl; 
    cout<<"AFTER REMOVING DATA FROM";
    sst.pop();
    sst.pop();
    sst.pop();
    sst.display();
    cout<<endl;
    cout<<"DISPLAYING PEEK ELEMENT IN THE STACK"<<endl;
    sst.peek();
}