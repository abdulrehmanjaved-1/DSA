#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"Enter the data for root node\n";
    int data;
    cin>>data;
    //create node now
    root=new Node(data);
    //base case
    if(data==-1){
        return NULL;
    }
    //for left node 
    cout<<"Enter value for left node"<<data<<endl;
    root->left=buildTree(root->left);
    //for right node 
    cout<<"Enter value for right node"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(Node* root){
    //first make a queue for LvlOrderTraversal
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //for root case (separator)
    while (!q.empty()){
        Node* temp=q.front(); //for root node (all parents)
        q.pop();
        //check for separator
        if(temp==NULL){
            cout<<"\n";
            if(!q.empty()){ //if true that means it have more to come so put NULL(separator) there too
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inOrderTraversal(Node *root){
    //as it is on LNR(left,node,right)
    //base case
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left); //for left child
    cout<<root->data<<" "; //for node  
    inOrderTraversal(root->right); //for right child 
}
void preOrderTraversal(Node *root){
    //as it is on NLR(node,left,right)
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" "; //for node  
    preOrderTraversal(root->left); //for left child
    preOrderTraversal(root->right); //for right child 
}
void postOrderTraversal(Node *root){
    //as it is on LRN(left,right,node)
    //base case
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left); //for left child
    postOrderTraversal(root->right); //for right child 
    cout<<root->data<<" "; //for node  
}
void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root\n";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    //testing value
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root=NULL;
    buildFromLevelOrder(root);
    // root=buildTree(root);
    // levelOrderTraversal(root);
    // inOrderTraversal(root);
    return 0;
}