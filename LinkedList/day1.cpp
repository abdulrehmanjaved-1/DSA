#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertAtTail(Node* &tail,int d){
        //create new node for new value insertion
        Node* temp=new Node(d);
        //change head now
        tail->next=temp;
        tail=temp;
    }
void reverseLinkedList(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    Node* forw=NULL;
    while(curr!=NULL){
        forw=curr->next;
        // cout<<"step forw"<<forw->data<<endl;
        curr->next=prev;
        // cout<<"step curr"<<curr->data<<endl;
        prev=curr;
        curr=forw;
    }
    head=prev;
}
Node* reverse1(Node* head){ //another solution
    //base case 
    if(head == NULL || head->next==NULL){
        return head;
    }
    Node* chotaHead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotaHead;
}
Node* getMiddle(Node* head){
    //base case
    if(head == NULL || head->next==NULL){
        return head;
    }
    //for two nodes
    if(head->next->next==NULL){
        return head->next;
    }
    Node* slow=head;
    Node* fast=head->next;
    while (fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
    
}
int main()
{
    Node* node1=new Node(10);
    Node* head=node1; 
    Node* tail=node1;
    insertAtTail(tail,20);
    insertAtTail(tail,30);
    insertAtTail(tail,40);
    insertAtTail(tail,50);
    reverseLinkedList(head);
    //also use recursive way for this
    cout<<getMiddle(head)->data<<endl; //middle two player approach big O of n...one more solution was mid=len/2;
    print(head);
    return 0;
}