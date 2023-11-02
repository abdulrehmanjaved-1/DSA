#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){this->data=data;this->next=NULL;}
};
void reverse_it(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    Node* forw=NULL;
    while (curr->next!=NULL)
    {
        /* code */
        forw=curr->next;
        curr->next=prev;
        //recursive call
        prev=curr;
        reverse_it(forw); 
    }  
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head,int d){
        //create new node for new value insertion
        Node* temp=new Node(d);
        //change head now
        temp->next=head;
        head=temp;
    }
int main()
{
    Node* node1=new Node(10);
    Node* head=node1;
    insertAtHead(head,13);
    reverse_it(head);
    print(head);
    return 0;
}