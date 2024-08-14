#include<string>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next=NULL;
};

Node *rearrange(Node *head){
    Node *prev=NULL;
    Node *curr=head,*Next=NULL;
    while(curr!=NULL){
        Next=curr->next;

        curr->next=prev;

        prev=curr;

        curr=Next;
    }
    head=prev;
    Node *result=new Node();
    result->next=prev;
    Node *current=head;
    while(current!=NULL){
        current=current->next;
        if(current!=NULL){
        if(prev->data <=current->data){
            prev->next=current;
            prev=prev->next;
        }
        else{
            prev->next=current->next;
        }}
        }
    return result->next;
}

int main(){
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();
    Node* temp = head;
    head->data=55;
    head->next=second;

    second->next=third;
    second->data=2;

    third->data=3;

    cout << "Current Linked List: " << endl;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    Node *result=rearrange(head);

    Node *prev=NULL;
    Node *curr=result,*Next=NULL;
    while(curr!=NULL){
        Next=curr->next;

        curr->next=prev;

        prev=curr;

        curr=Next;
    }
    result=prev;
    cout << endl;
    cout << endl;
    cout << "Modified Linked List: " << endl;

    while(result!=NULL){
        cout<<result->data<<" -> ";
        result=result->next;
    }
}
