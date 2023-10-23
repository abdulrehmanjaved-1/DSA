#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int length(Node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
void insertAtHead(Node* &head,int d){
    Node* temp=head;
    Node* newNode=new Node(d);
    newNode->next=temp;
    temp->prev=newNode;
    head=newNode;
}
void insertAtTail(Node* &head,int d,Node* &tail){
    int count=1;
    Node* temp=head;
    while(count<length(head)){
        temp=temp->next;
        count++;
    }
    Node* newNode=new Node(d);
    temp->next=newNode;
    newNode->prev=temp;
    tail=newNode;
}
void insertAtPosition(Node* &head,Node* &tail,int d,int position){
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    else if(position==length(head)+1){
        insertAtTail(head,d,tail);
        return;
    }
    else{
        Node* temp=head;
        int cnt=1;
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        Node* newNode=new Node(d);
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next->prev=newNode;//this line is necessary or not? ans: yes it is necessary because we have to make prev of next node point to new node
    }
}
int main()
{   
    //if you dont want to initialize node1 ,you can handle case of null in insertAtHead function and other functions
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=NULL;
    // insertAtHead(head,11);
    insertAtTail(head,12,tail);
    insertAtPosition(head,tail,13,2);
    print(head);
    // cout<<"length of this list is "<<length(head)<<endl;
    return 0;
}