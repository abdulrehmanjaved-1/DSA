//insert in head,tail,middle

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor for free up memory
    ~Node(){
        if(next!=NULL){
            
            int value=this->data;
            delete next;
            this->next=NULL;
        }
        cout<<"Deleting node with data "<<data<<endl;
    }
};
void insertAtHead(Node* &head,int d){
        //create new node for new value insertion
        Node* temp=new Node(d);
        //change head now
        temp->next=head;
        head=temp;
    }
void insertAtTail(Node* &tail,int d){
        //create new node for new value insertion
        Node* temp=new Node(d);
        //change head now
        tail->next=temp;
        tail=temp;
    }
void deleteNode(Node* &head,int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        //deleting any middle or last node
        Node* curr=head;
        Node* prev=NULL; //why prev is null ? because we have to delete node at position 2,then we have to make prev point to head
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void insertAtMiddle(Node* &tail,Node* &head,int position,int d){
        //for position == 1
        if(position==1){
            insertAtHead(head,d);
            return;
        }     
        //make tempt o point to head
        Node* temp=head;
        int cnt=1;
        //create new node for new value insertion
        while (cnt<position-1)
        {
            temp=temp->next;
            cnt++;
        }
        //check for last position(because temp->next is NULL ,it means we are at last position)
        if(temp->next==NULL){
            insertAtTail(tail,d);
            return;
        }
        //create node for new value insertion
        Node* n=new Node(d);
        //change pointer of new node
        n->next=temp->next;
        temp->next=n;
    }
void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        //to increment
        temp=temp->next;
    }
}
int main()
{
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    //head pointing to node1
    Node* head=node1;
    Node* tail=node1;
    // print(head);
    //insert some int at head
    insertAtTail(tail,15);
    insertAtHead(head,9);
    insertAtTail(tail,17);

    //middle
    insertAtMiddle(tail,head,3,12);
    //where we will use tail?as we are passing it by reference. we will use it when we want to insert at tail
    // print(head);
    deleteNode(head,3);
    print(head);
    return 0;
}